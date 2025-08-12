#include <bits/stdc++.h>

// https://github.com/delfrrr/delaunator-cpp
#include "delaunator.hpp"

using namespace std;
using pii = pair<int, int>;

int N, M, K;
vector<vector<int>> G; // 0 ~ (N - 1) : PROCESSOR, N ~ (N + M - 1) : SORTER, (N + M) : INLET
vector<vector<double>> P;

enum class NodeType { PROCESSOR, SORTER, INLET };
struct Node 
{
    NodeType type;
    int sorter_type, processor_type;    // sorter_type : 0 ~ (K - 1), processor_type : 0 ~ (N - 1)
    bool is_used;

    int level;                          // level = max(max(parents.level) + 1, level) 
    vector<int> parents_idx;            // PROCESSOR : multi, SORTER : multi, INLET : null 
    int exit1_dest, exit2_dest;         // PROCESSOR : null, SORTER : exit1 == exit2 or exit1 != exit2, INLET : exit1 == exit2 

    double waste_sum;                   // sum(waste_details)
    double score;                       // max(waste_details) / waste_sum
    vector<double> waste_details;       // node_info[exit1_dest].waste_details[i] += waste_details[i] * p[sorter_type][i] ...
};
vector<Node> node_info; 

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> N >> M >> K;

    vector<double> position(2 * (N + M + 1));
    for (int i = 0; i < (N + M) * 2; i += 2) cin >> position[i] >> position[i + 1];
    position[(N + M) * 2] = 0;
    position[(N + M) * 2 + 1] = 5000;
    
    P.resize(K, vector<double>(N));
    for (auto &row : P) for (auto &val : row) cin >> val;

    G.resize(N + M + 1);
    vector<set<int>> temp_G(N + M + 1);
    delaunator::Delaunator d(position);
    for (int i = 0; i < d.triangles.size(); i += 3) {
        int p0 = d.triangles[i];
        int p1 = d.triangles[i + 1];
        int p2 = d.triangles[i + 2];
        
        temp_G[p0].insert(p1);
        temp_G[p0].insert(p2);
        temp_G[p1].insert(p0);
        temp_G[p1].insert(p2);
        temp_G[p2].insert(p0);
        temp_G[p2].insert(p1);
    }
    for (int i = 0; i < N + M + 1; i++) G[i].assign(temp_G[i].begin(), temp_G[i].end());

    // cout << G.size() << '\n';
    // for (int i = 0; i < G.size(); ++i)
    // {
    //     cout << "G[" << i << "]: ";
    //     for (int e : G[i]) cout << e << ' ';
    //     cout << '\n';
    // } 
    
    node_info.resize(N + M + 1);
    for (int i = 0; i < N; ++i) 
    {
        node_info[i].type = NodeType::PROCESSOR;
        node_info[i].is_used = false;
        node_info[i].level = numeric_limits<int>::max();
        node_info[i].score = 0.0;
        node_info[i].waste_sum = 0.0;
        node_info[i].waste_details.resize(N, 0.0);
    }
    for (int i = N; i < N + M; ++i) 
    {
        node_info[i].type = NodeType::SORTER;
        node_info[i].is_used = false;
        node_info[i].level = 0;
        node_info[i].score = 0.0;
        node_info[i].waste_sum = 0.0;
        node_info[i].waste_details.resize(N, 0.0);
    }
    node_info[N + M].type = NodeType::INLET;
    node_info[N + M].is_used = true;
    node_info[N + M].level = 0;
    node_info[N + M].score = 1.0 / N;
    node_info[N + M].waste_sum = 1.0; 
    node_info[N + M].waste_details.resize(N, 1.0 / N);
}

void cart()
{
    auto gini = [](const vector<double> &d, double sum) -> double
    {

    };


}

int main()
{
    init();
    cart();
}
