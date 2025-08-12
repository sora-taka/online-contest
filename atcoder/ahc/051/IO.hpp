#include <bits/stdc++.h>

#include "delaunator.hpp"

using namespace std;

namespace IO
{
    vector<int> grid_to_original; // Map grid index to original index
    vector<int> original_to_grid; 


    void input(int &N, int &M, int &K, vector<vector<int>> &G, vector<vector<double>> &P)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        int m;
        cin >> N >> m >> K;

        // Read all original positions
        vector<pair<int, int>> original_positions; // Store original positions
        original_positions.resize(N + m + 1);
        for (int i = 0; i < N + m; ++i)
        {
            cin >> original_positions[i].first >> original_positions[i].second;
        }
        original_positions[N + m] = {0, 5000}; // inlet position

        P.resize(K, vector<double>(N));
        for (auto &row : P) for (auto &val : row) cin >> val;

        // Create 20x20 grid system (400 cells total)
        const int GRID_SIZE = 20;
        const int CELL_WIDTH = 10000 / GRID_SIZE;  // 500 units per cell
        const int CELL_HEIGHT = 10000 / GRID_SIZE; // 500 units per cell

        vector<vector<bool>> grid_cells(GRID_SIZE, vector<bool>(GRID_SIZE, true));
        original_to_grid.assign(N + m + 1, -1);

        // processor
        for (int i = 0; i < N; ++i)
        {
            auto [x, y] = original_positions[i];
            grid_to_original.push_back(i);
            original_to_grid[i] = grid_to_original.size() - 1;
        }

        // sorter
        for (int i = N; i < N + m; ++i)
        {
            auto [x, y] = original_positions[i];

            int grid_x = min(x / CELL_WIDTH, GRID_SIZE - 1);
            int grid_y = min(y / CELL_HEIGHT, GRID_SIZE - 1);

            if (grid_cells[grid_x][grid_y])
            {
                // This cell is empty, place this node
                grid_cells[grid_x][grid_y] = false;
                grid_to_original.push_back(i);
                original_to_grid[i] = grid_to_original.size() - 1;
            }
        }
        // inlet
        grid_to_original.push_back(N + m);
        original_to_grid[N + m] = grid_to_original.size() - 1;

        // G
        G.resize(grid_to_original.size());
        vector<set<int>> temp_G(grid_to_original.size());
        vector<double> positions_flat;
        for (int e : grid_to_original)
        {
            positions_flat.push_back(original_positions[e].first);
            positions_flat.push_back(original_positions[e].second);
        }
        delaunator::Delaunator d(positions_flat);
        for (size_t i = 0; i < d.triangles.size(); i += 3)
        {
            int p0 = d.triangles[i];
            int p1 = d.triangles[i + 1];
            int p2 = d.triangles[i + 2];

            temp_G[p0].insert(p1); temp_G[p0].insert(p2);
            temp_G[p1].insert(p0); temp_G[p1].insert(p2);
            temp_G[p2].insert(p0); temp_G[p2].insert(p1);
        }

        // del processor to inlet and processor toprocessor 
        for (int i = 0; i < N; i++)
        {
            vector<int> del;
            for (int e : temp_G[i])
            {
                if (e < N || e == temp_G.size() - 1) del.push_back(e);
            }
            for (int e : del) 
            {
                temp_G[i].erase(e);
                temp_G[e].erase(i);
            }

        }
        for (int i = 0; i < temp_G.size(); i++) G[i].assign(temp_G[i].begin(), temp_G[i].end());
        
        M = G.size() - N - 1;

        // warning processor to processor (small probability, ignore)


    }

    void output(const vector<int> &processor_assignment, const int &inlet_connection, const vector<int> &sorter_types, const vector<int> &sorter_output1, const vector<int> &sorter_output2)
    {
        int N = processor_assignment.size();

        for (int e : processor_assignment) cout << e << ' ';

        cout << '\n' << grid_to_original[inlet_connection] << '\n';
        
        for (int i = N; i < original_to_grid.size() - 1; i++)
        {
            if (original_to_grid[i] == -1) 
            {
                cout << -1;
            }
            else if (sorter_types[original_to_grid[i] - N] == -1)
            {
                cout << -1;
            }
            else
            {
                if (sorter_output1[original_to_grid[i] - N] == -1 && sorter_output2[original_to_grid[i] - N] == -1) 
                {
                    cout << -1 << ' ';
                }
                else
                {
                    cout << sorter_types[original_to_grid[i] - N] << ' ';
                    if (sorter_output1[original_to_grid[i] - N] == -1)
                    {
                        cout << grid_to_original[sorter_output2[original_to_grid[i] - N]] << ' ' << grid_to_original[sorter_output2[original_to_grid[i] - N]];
                    }
                    else if (sorter_output2[original_to_grid[i] - N] == -1)
                    {
                        cout << grid_to_original[sorter_output1[original_to_grid[i] - N]] << ' ' << grid_to_original[sorter_output1[original_to_grid[i] - N]];
                    }
                    else
                    {
                        cout << grid_to_original[sorter_output1[original_to_grid[i] - N]] << ' ' << grid_to_original[sorter_output2[original_to_grid[i] - N]];
                    }
                }

                
            }
            cout << '\n';
        }
    }

} // namespace IO
