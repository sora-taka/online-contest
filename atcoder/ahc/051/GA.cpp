#include <bits/stdc++.h>
#include "IO.hpp"

using namespace std;

// 全局调试开关
bool DEBUG_MODE = true;
void debugLog(const string &msg) { if (DEBUG_MODE) cerr << "[DEBUG] " << msg << '\n';}

int N, M, K;              // N 种垃圾，M 个分拣机位置，K 种分拣机类型
vector<vector<int>> G;    // Adjacency list 0~ N-1 processor，N~N+M-1 sorter，N+M inlet
vector<vector<double>> P; // P[i][j] = 分拣机类型i对垃圾j的出口1概率

struct Individual
{
    vector<int> processor_assignment;           // 长度N，processor_assignment[i] = 处理器i负责的垃圾类型
    int inlet_connection;                       // 入口连接到哪个节点
    vector<int> sorter_types;                   // 长度M，sorter_types[i] = 位置N+i的分拣机类型（-1表示不安装）
    vector<int> sorter_output1, sorter_output2; // 长度M，output1[i] = 位置N+i的分拣机的1号出口， output2[i] = 位置N+i的分拣机的2号出口
    vector<vector<int>> parents;
    
    // 表现体字段 - 环路修复后的有效连接
    vector<int> effective_output1, effective_output2; // 长度M，修复后的有效连接
    vector<bool> processor_reachable;                 // 长度N，标记processor是否可达inlet

    double fitness;

    Individual()
    {
        processor_assignment.resize(N); iota(processor_assignment.begin(), processor_assignment.end(), 0);
        sorter_types.assign(M, -1);
        inlet_connection = -1;
        sorter_output1.assign(M, -1);
        sorter_output2.assign(M, -1);
        parents.resize(N + M + 1);
        
        // 初始化表现体字段
        effective_output1.assign(M, -1);
        effective_output2.assign(M, -1);
        processor_reachable.assign(N, false);
        
        fitness = -1;
    }
};

class WasteSortingGA
{
private:
    vector<Individual> population;
    int population_size;
    double crossover_rate;
    double mutation_rate;
    mt19937 rng;

public:
    WasteSortingGA(int pop_size, double cro_rate, double mut_rate)
    {
        population_size = pop_size;
        crossover_rate = cro_rate;
        mutation_rate = mut_rate;
        rng.seed(random_device{}());
    }

    // 初始化种群
    void initializePopulation()
    {
        population.clear();
        population.reserve(population_size);

        for (int i = 0; i < population_size; i++)
        {
            Individual ind;
            randomizeIndividual(ind);
            population.push_back(ind);
        }
    }

    void randomizeIndividual(Individual &ind)
    {
        // 重置所有数据结构
        for(auto &p : ind.parents) p.clear();
        
        // 随机分配处理器
        shuffle(ind.processor_assignment.begin(), ind.processor_assignment.end(), rng);

        // 随机分配 sorter_type，每个 sorter 分配一个 0 ~ K - 1的值
        for(int i = 0; i < M; i++) {
            ind.sorter_types[i] = uniform_int_distribution<int>(0, K-1)(rng);
        }

        // 随机构建树结构
        // 在 G 中随机选择一个 inlet 的子节点，设置成 inlet_connection，并更新被选节点的parents
        int inlet = N + M; // inlet节点索引
        if(G[inlet].empty()) {
            debugLog("Warning: inlet has no connections in graph G");
            return;
        }
        
        int inlet_child_idx = uniform_int_distribution<int>(0, G[inlet].size()-1)(rng);
        ind.inlet_connection = G[inlet][inlet_child_idx];
        ind.parents[ind.inlet_connection].push_back(inlet);
        
        // 从 inlet_connection 开始 BFS 构建树
        vector<bool> used(N + M + 1, false);
        used[inlet] = true;
        used[ind.inlet_connection] = true;
        
        queue<int> q;
        q.push(ind.inlet_connection);
        
        while(!q.empty()) {
            int current = q.front();
            q.pop();
            
            // 如果当前节点是sorter (N <= current < N+M)，需要连接两个输出
            if(current >= N && current < N + M) {
                int sorter_idx = current - N;
                
                // 收集所有可用的未使用节点
                vector<int> available_nodes;
                for(int node : G[current]) {
                    if(!used[node]) {
                        available_nodes.push_back(node);
                    }
                }
                
                // 随机选择最多两个节点连接
                if(available_nodes.size() >= 2) {
                    // 随机打乱可用节点
                    shuffle(available_nodes.begin(), available_nodes.end(), rng);
                    
                    // 连接前两个节点
                    int output1 = available_nodes[0];
                    int output2 = available_nodes[1];
                    
                    ind.sorter_output1[sorter_idx] = output1;
                    ind.sorter_output2[sorter_idx] = output2;
                    
                    // 更新parents和used状态
                    ind.parents[output1].push_back(current);
                    ind.parents[output2].push_back(current);
                    used[output1] = true;
                    used[output2] = true;
                    
                    // 将新连接的节点加入BFS队列
                    q.push(output1);
                    q.push(output2);
                } else if(available_nodes.size() == 1) {
                    // 只有一个可用节点
                    int output1 = available_nodes[0];
                    ind.sorter_output1[sorter_idx] = output1;
                    ind.sorter_output2[sorter_idx] = -1; // 没有第二个输出
                    
                    ind.parents[output1].push_back(current);
                    used[output1] = true;
                    q.push(output1);
                } else {
                    // 没有可用节点，设置输出为-1
                    ind.sorter_output1[sorter_idx] = -1;
                    ind.sorter_output2[sorter_idx] = -1;
                }
            }
        }
    }
    
    bool randomReverseDFS(int processor, const Individual &ind, vector<bool> &path_visited) {
        int current = processor;
        int inlet = N + M;
        
        while(current != inlet) {
            // 如果当前节点已经在路径中，检测到环
            if(path_visited[current]) {
                return false;
            }
            
            // 标记当前节点在路径中
            path_visited[current] = true;
            
            // 获取当前节点的所有父节点
            if(ind.parents[current].empty()) {
                // 没有父节点，无法到达inlet
                return false;
            }
            
            // 随机选择一个父节点继续向上
            int parent_idx = uniform_int_distribution<int>(0, ind.parents[current].size()-1)(rng);
            current = ind.parents[current][parent_idx];
        }
        
        // 成功到达inlet
        return true;
    }
    
    void buildEffectiveConnections(Individual &ind) {
        // 重置有效连接
        for(int i = 0; i < M; i++) {
            ind.effective_output1[i] = -1;
            ind.effective_output2[i] = -1;
        }
        
        // 标记哪些节点在有效路径上
        vector<bool> node_in_valid_path(N + M + 1, false);
        
        // 为每个可达的processor标记其到inlet的路径
        for(int p = 0; p < N; p++) {
            if(ind.processor_reachable[p]) {
                // 再次从processor到inlet，标记路径上的所有节点
                markValidPath(p, ind, node_in_valid_path);
            }
        }
        
        // 构建有效的sorter连接
        for(int i = 0; i < M; i++) {
            int sorter_node = N + i;
            if(node_in_valid_path[sorter_node]) {
                // 检查output1是否在有效路径上
                if(ind.sorter_output1[i] != -1 && node_in_valid_path[ind.sorter_output1[i]]) {
                    ind.effective_output1[i] = ind.sorter_output1[i];
                }
                // 检查output2是否在有效路径上
                if(ind.sorter_output2[i] != -1 && node_in_valid_path[ind.sorter_output2[i]]) {
                    ind.effective_output2[i] = ind.sorter_output2[i];
                }
            }
        }
    }
    
    void markValidPath(int processor, const Individual &ind, vector<bool> &node_in_valid_path) {
        int current = processor;
        int inlet = N + M;
        vector<bool> path_visited(N + M + 1, false);
        vector<int> path;
        
        // 使用DFS找到一条有效路径
        while(current != inlet && !path_visited[current] && !ind.parents[current].empty()) {
            path_visited[current] = true;
            path.push_back(current);
            
            // 随机选择一个父节点（与之前的DFS保持一致）
            int parent_idx = uniform_int_distribution<int>(0, ind.parents[current].size()-1)(rng);
            current = ind.parents[current][parent_idx];
        }
        
        // 如果成功到达inlet，标记路径上的所有节点
        if(current == inlet) {
            for(int node : path) {
                node_in_valid_path[node] = true;
            }
            node_in_valid_path[inlet] = true;
        }
    }
    
    double calculateReachProbability(int current_node, int waste_type, int target_processor, 
                                     const Individual &ind, unordered_map<int,double> &memo) {
        // 到达目标processor
        if(current_node == target_processor) return 1.0;
        
        // 到达错误processor
        if(current_node < N && current_node != target_processor) return 0.0;
        
        // 检查记忆化缓存
        if(memo.count(current_node)) return memo[current_node];
        
        double prob = 0.0;
        
        // 如果是sorter节点
        if(current_node >= N && current_node < N + M) {
            int sorter_idx = current_node - N;
            int sorter_type = ind.sorter_types[sorter_idx];
            
            // 如果sorter_type无效，概率为0
            if(sorter_type == -1) {
                memo[current_node] = 0.0;
                return 0.0;
            }
            
            int output1 = ind.effective_output1[sorter_idx];
            int output2 = ind.effective_output2[sorter_idx];
            double p1 = P[sorter_type][waste_type]; // 本来到output1的概率
            
            // 情况1：两个输出都有效
            if(output1 != -1 && output2 != -1) {
                prob += p1 * calculateReachProbability(output1, waste_type, target_processor, ind, memo);
                prob += (1.0 - p1) * calculateReachProbability(output2, waste_type, target_processor, ind, memo);
            }
            // 情况2：只有output1有效，所有流量走output1
            else if(output1 != -1 && output2 == -1) {
                prob += 1.0 * calculateReachProbability(output1, waste_type, target_processor, ind, memo);
            }
            // 情况3：只有output2有效，所有流量走output2
            else if(output1 == -1 && output2 != -1) {
                prob += 1.0 * calculateReachProbability(output2, waste_type, target_processor, ind, memo);
            }
            // 情况4：两个输出都无效（死路），概率为0
            else {
                prob = 0.0;
            }
        }
        
        memo[current_node] = prob;
        return prob;
    }

    double calculateFitness(Individual &ind) {
        // 确保表现体已构建
        buildPhenotype(ind);
        
        double total_error = 0.0;
        
        for(int waste_type = 0; waste_type < N; waste_type++) {
            // 找到负责这种垃圾的processor
            int target_processor = -1;
            for(int p = 0; p < N; p++) {
                if(ind.processor_assignment[p] == waste_type) {
                    target_processor = p;
                    break;
                }
            }
            
            double prob = 0.0;
            if(target_processor != -1 && ind.processor_reachable[target_processor]) {
                // 计算垃圾类型waste_type到达target_processor的概率
                unordered_map<int,double> memo;
                prob = calculateReachProbability(ind.inlet_connection, waste_type, target_processor, ind, memo);
            }
            
            total_error += (1.0 - prob);
            
            if(DEBUG_MODE) {
                debugLog("Waste " + to_string(waste_type) + " -> Processor " + to_string(target_processor) + 
                        " probability: " + to_string(prob));
            }
        }
        
        // 适应度 = 负的平均错误率（这样GA会最大化适应度，最小化错误率）
        double fitness = -total_error / N;
        
        debugLog("Fitness calculated: " + to_string(fitness) + " (avg error: " + to_string(total_error / N) + ")");
        return fitness;
    }

    void buildPhenotype(Individual &ind) {
        // 1. 重置processor可达性
        for(int i = 0; i < N; i++) {
            ind.processor_reachable[i] = false;
        }
        
        // 2. 对每个processor进行随机反向DFS
        for(int p = 0; p < N; p++) {
            vector<bool> path_visited(N + M + 1, false);
            if(randomReverseDFS(p, ind, path_visited)) {
                ind.processor_reachable[p] = true;
            }
        }
        
        // 3. 构建有效连接
        buildEffectiveConnections(ind);
        
        debugLog("Phenotype built - reachable processors: " + to_string(count(ind.processor_reachable.begin(), ind.processor_reachable.end(), true)));
    }

    void printIndividualStructure(const Individual &ind) {
        if (!DEBUG_MODE) return;
        
        debugLog("=== Individual Structure ===");
        debugLog("Processor assignment: ");
        for(int i = 0; i < N; i++) {
            cerr << "  Processor " << i << " -> Waste " << ind.processor_assignment[i] << '\n';
        }
        
        debugLog("Inlet connection: " + to_string(ind.inlet_connection));
        
        debugLog("Sorter types and outputs:");
        for(int i = 0; i < M; i++) {
            cerr << "  Sorter " << (N+i) << " type=" << ind.sorter_types[i] 
                 << " out1=" << ind.sorter_output1[i] 
                 << " out2=" << ind.sorter_output2[i] << '\n';
        }
        
        debugLog("Effective outputs:");
        for(int i = 0; i < M; i++) {
            cerr << "  Sorter " << (N+i) 
                 << " eff_out1=" << ind.effective_output1[i] 
                 << " eff_out2=" << ind.effective_output2[i] << '\n';
        }
        
        debugLog("Processor reachability:");
        for(int i = 0; i < N; i++) {
            if(ind.processor_reachable[i]) {
                cerr << "  Processor " << i << " is reachable" << '\n';
            }
        }
        
        debugLog("Parents structure:");
        for(int i = 0; i < N + M + 1; i++) {
            if(!ind.parents[i].empty()) {
                cerr << "  Node " << i << " parents: ";
                for(int p : ind.parents[i]) {
                    cerr << p << " ";
                }
                cerr << '\n';
            }
        }
    }

    Individual tournamentSelect() {
        int tournament_size = 3;
        Individual best_in_tournament = population[uniform_int_distribution<int>(0, population_size-1)(rng)];
        
        for(int i = 1; i < tournament_size; i++) {
            Individual candidate = population[uniform_int_distribution<int>(0, population_size-1)(rng)];
            if(candidate.fitness > best_in_tournament.fitness) {
                best_in_tournament = candidate;
            }
        }
        
        return best_in_tournament;
    }
    
    Individual pmxCrossover(const Individual &parent1, const Individual &parent2) {
        Individual child = parent1;  // 从父代1开始
        
        // PMX交叉：处理processor_assignment排列
        if(N > 1) {
            // 1. 随机选择两个交叉点
            int point1 = uniform_int_distribution<int>(0, N-2)(rng);
            int point2 = uniform_int_distribution<int>(point1+1, N-1)(rng);
            
            // 2. 复制父代2的中间段到child
            for(int i = point1; i <= point2; i++) {
                child.processor_assignment[i] = parent2.processor_assignment[i];
            }
            
            // 3. 处理冲突：对于中间段之外的位置
            for(int i = 0; i < N; i++) {
                if(i >= point1 && i <= point2) continue;  // 跳过中间段
                
                int value = parent1.processor_assignment[i];
                
                // 检查这个值是否已经在中间段中出现
                bool conflict = false;
                for(int j = point1; j <= point2; j++) {
                    if(child.processor_assignment[j] == value) {
                        conflict = true;
                        break;
                    }
                }
                
                if(conflict) {
                    // 找到映射链：value -> 在中间段中被什么替换了
                    int current = value;
                    while(true) {
                        // 在父代2中找到current的位置
                        int pos_in_p2 = -1;
                        for(int k = 0; k < N; k++) {
                            if(parent2.processor_assignment[k] == current) {
                                pos_in_p2 = k;
                                break;
                            }
                        }
                        
                        if(pos_in_p2 >= point1 && pos_in_p2 <= point2) {
                            // current在中间段，查看父代1在这个位置的值
                            current = parent1.processor_assignment[pos_in_p2];
                        } else {
                            // current不在中间段，可以使用
                            break;
                        }
                    }
                    child.processor_assignment[i] = current;
                } else {
                    // 没有冲突，保持父代1的值
                    child.processor_assignment[i] = value;
                }
            }
        }
        
        // 均匀交叉sorter_types
        for(int i = 0; i < M; i++) {
            if(uniform_real_distribution<double>(0,1)(rng) < 0.5) {
                child.sorter_types[i] = parent2.sorter_types[i];
            }
        }
        
        return child;
    }
    
    Individual subtreeCrossover(const Individual &parent1, const Individual &parent2) {
        Individual child = parent1;  // 复制父代1作为基础
        
        // 随机选择连续sorter区域进行交换
        int region_size = uniform_int_distribution<int>(2, min(5, M))(rng);
        int start_idx = uniform_int_distribution<int>(0, M - region_size)(rng);
        
        // 交换选定区域的sorter_types
        for(int i = start_idx; i < start_idx + region_size; i++) {
            child.sorter_types[i] = parent2.sorter_types[i];
        }
        
        return child;
    }
    
    void mutate(Individual &ind) {
        // 1. processor分配变异（概率0.05）
        if(uniform_real_distribution<double>(0,1)(rng) < 0.05) {
            int i = uniform_int_distribution<int>(0, N-1)(rng);
            int j = uniform_int_distribution<int>(0, N-1)(rng);
            swap(ind.processor_assignment[i], ind.processor_assignment[j]);
        }
        
        // 2. sorter类型变异（每个sorter概率0.05）
        for(int i = 0; i < M; i++) {
            if(uniform_real_distribution<double>(0,1)(rng) < 0.05) {
                ind.sorter_types[i] = uniform_int_distribution<int>(0, K-1)(rng);
            }
        }
    }
    
    void evaluatePopulation() {
        for(int i = 0; i < population_size; i++) {
            population[i].fitness = calculateFitness(population[i]);
        }
    }
    
    void sortPopulation() {
        sort(population.begin(), population.end(), [](const Individual &a, const Individual &b) {
            return a.fitness > b.fitness;  // 按适应度降序排列
        });
    }

    Individual evolve(int max_generations = 20) {
        // 1. 初始化种群
        initializePopulation();
        evaluatePopulation();
        sortPopulation();
        
        Individual best_ever = population[0];
        
        debugLog("Initial population created. Best fitness: " + to_string(best_ever.fitness));
        
        // 2. 进化主循环
        for(int generation = 0; generation < max_generations; generation++) {
            vector<Individual> new_population;
            
            // 精英保留：保留前10%最优个体
            int elite_count = population_size * 0.1;
            for(int i = 0; i < elite_count; i++) {
                new_population.push_back(population[i]);
            }
            
            // 生成剩余个体通过选择、交叉、变异
            while(new_population.size() < population_size) {
                // 选择父代
                Individual parent1 = tournamentSelect();
                Individual parent2 = tournamentSelect();
                
                Individual child;
                
                // 交叉操作
                if(uniform_real_distribution<double>(0,1)(rng) < crossover_rate) {
                    // 70%概率PMX交叉，30%概率伪子树交叉
                    if(uniform_real_distribution<double>(0,1)(rng) < 0.7) {
                        child = pmxCrossover(parent1, parent2);
                    } else {
                        child = subtreeCrossover(parent1, parent2);
                    }
                } else {
                    // 不交叉，直接复制父代1
                    child = parent1;
                }
                
                // 变异操作
                mutate(child);
                
                // 重新构建表现体和计算适应度
                child.fitness = calculateFitness(child);
                
                new_population.push_back(child);
            }
            
            // 3. 更新种群
            population = new_population;
            sortPopulation();
            
            // 4. 更新全局最优
            if(population[0].fitness > best_ever.fitness) {
                best_ever = population[0];
            }
            
            // 5. 输出进度（每5代）
            if(generation % 5 == 0 || generation == max_generations - 1) {
                debugLog("Generation " + to_string(generation) + 
                        ", Best: " + to_string(population[0].fitness) + 
                        ", Avg: " + to_string(calculateAverageFitness()) + 
                        ", Global Best: " + to_string(best_ever.fitness));
            }
        }
        
        debugLog("Evolution completed. Final best fitness: " + to_string(best_ever.fitness));
        return best_ever;
    }
    
    double calculateAverageFitness() {
        double sum = 0.0;
        for(const auto &ind : population) {
            sum += ind.fitness;
        }
        return sum / population_size;
    }
    
};

int main()
{

    IO::input(N, M, K, G, P);

    WasteSortingGA ga(100, 0.8, 0.1);

    int max_generations = 1000;
    Individual best_solution = ga.evolve(max_generations);

    // Individual best_solution = ga.evolve(1000);

    IO::output(best_solution.processor_assignment, best_solution.inlet_connection, best_solution.sorter_types, best_solution.effective_output1, best_solution.effective_output2);

    return 0;
}