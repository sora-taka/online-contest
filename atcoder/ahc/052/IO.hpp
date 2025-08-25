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
