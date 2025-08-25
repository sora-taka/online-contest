#include <bits/stdc++.h>

using namespace std;

struct Robot {
    int x, y;    

    Robot() {}
    Robot(int x, int y) : x(x), y(y){}
};

struct Grid {
    int N, M, K;
    vector<Robot> robots;
    vector<string> v_walls, h_walls;  

    int visited_count;
    vector<vector<bool>> visited;     


    vector<vector<char>> button_config;  
    vector<int> operations;              
    
    Grid() {}
    void init(int n, int m, int k) {
        N = n; M = m; K = k;
        robots.resize(M);
        v_walls.resize(N), h_walls.resize(N-1);

        visited_count = 0;
        visited.assign(N, vector<bool>(N, false));

        button_config.assign(K, vector<char>(M, 'S'));
    }
};

namespace IO {
    
    void input(Grid& grid) {
        int N, M, K;
        cin >> N >> M >> K;
        grid.init(N, M, K);
        
        for (int i = 0; i < M; i++) {
            int x, y;
            cin >> x >> y;
            grid.robots[i] = Robot(x, y);
            if (!grid.visited[x][y]) {
                grid.visited_count++;
                grid.visited[x][y] = true; 
            }
        }
        
        for (int i = 0; i < N; i++) {
            cin >> grid.v_walls[i];
        }
        
        for (int i = 0; i < N-1; i++) {
            cin >> grid.h_walls[i];
        }
    }
    
    void output(const Grid& grid) {
        for (int k = 0; k < grid.K; k++) {
            for (int m = 0; m < grid.M; m++) {
                cout << grid.button_config[k][m] << ' ';
            }
            cout << "\n";
        }

        for (int op : grid.operations) {
            cout << op << "\n";
        }
    }
}


bool DEBUG_MODE = false;   
void debugLog(const string &msg) { if (DEBUG_MODE) cerr << "[DEBUG] " << msg << '\n';}

// 检查是否可以从(x,y)移动到(nx,ny)
bool checkMove(const Grid& grid, int x, int y, int nx, int ny) {
    if (nx < 0 || nx >= grid.N || ny < 0 || ny >= grid.N) return false;
    
    // 检查水平移动的墙壁
    if (x == nx) {
        if (ny > y) {  // 向右移动
            return grid.v_walls[x][y] == '0';
        } else {  // 向左移动
            return grid.v_walls[x][ny] == '0';
        }
    }
    
    // 检查垂直移动的墙壁
    if (y == ny) {
        if (nx > x) {  // 向下移动
            return grid.h_walls[x][y] == '0';
        } else {  // 向上移动
            return grid.h_walls[nx][y] == '0';
        }
    }

    return false;
}

// 模拟一步操作
void simulateStep(Grid& grid, int button_id) {
    for (int i = 0; i < grid.M; i++) {
        char action = grid.button_config[button_id][i];
        Robot& robot = grid.robots[i];
        
        int nx = robot.x, ny = robot.y;
        switch (action) {
            case 'U': nx--; break;
            case 'D': nx++; break;
            case 'L': ny--; break; 
            case 'R': ny++; break;
            case 'S': break;
        }
        
        if (action != 'S' && checkMove(grid, robot.x, robot.y, nx, ny)) {
            robot.x = nx;
            robot.y = ny;
        }
        
        if (!grid.visited[robot.x][robot.y]) {
            grid.visited[robot.x][robot.y] = true;
            grid.visited_count++;
        }
    }
}

void generateSimpleConfig(Grid& grid) {
    
    int max_operations = 2 * grid.N * grid.N; 
    
    grid.button_config[0].assign(grid.M, 'R');  // 右
    grid.button_config[1].assign(grid.M, 'D');  // 下
    grid.button_config[2].assign(grid.M, 'L');  // 左
    grid.button_config[3].assign(grid.M, 'U');  // 上

    int global_radius = -1;
    
    for (int step = 0; step < max_operations; ) {
        if (grid.visited_count == grid.N * grid.N) break;
        
        global_radius += 2;
        
        for (int j = 0; step < max_operations && j < global_radius; j++)
        {
            simulateStep(grid, 0);
            grid.operations.push_back(0);
            step++;
        }

        for (int j = 0; step < max_operations && j < global_radius; j++)
        {
            simulateStep(grid, 1);
            grid.operations.push_back(1);
            step++;
        }

        for (int j = 0; step < max_operations && j < global_radius; j++)
        {
            simulateStep(grid, 2);
            grid.operations.push_back(2);
            step++;
        }

        for (int j = 0; step < max_operations && j < global_radius; j++)
        {
            simulateStep(grid, 3);
            grid.operations.push_back(3);
            step++;
        }
        if (step < max_operations)
        {
            simulateStep(grid, 3);
            grid.operations.push_back(3);
            step++;
        }
        if (step < max_operations)
        {
            simulateStep(grid, 2);
            grid.operations.push_back(2);
            step++;
        }
        if (global_radius > 30) break;
    }
        

}

int main()
{
    Grid grid;

    IO::input(grid);

    generateSimpleConfig(grid);
    
    IO::output(grid);
    
    return 0;
}