#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (auto & e : s) cin >> e;
    vector<vector<vector<int>>> deep(h, vector<vector<int>>(w, vector<int>(2, 2'000'000'000)));

    queue<tuple<int, int, int>> q;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] == 'S') 
            {
                q.push({i, j, 0});
                deep[i][j][0] = 0;
                break;
            }
        }
        if (!q.empty()) break;
    }

    while (!q.empty())
    {
        auto [i, j, k] = q.front();
        q.pop();
        if (s[i][j] == 'G')
        {
            // for (int i = 0; i < h; i++)
            // {
            //     for (int j = 0; j < w; j++)
            //     {
            //         cout << deep[i][j][0] << ", " << deep[i][j][1] << " ";
            //     }
            //     cout << '\n';
            // }
            cout << deep[i][j][k] << '\n';
            return;
        }
        for (int di = -1; di <= 1; di++)
        {
            for (int dj = -1; dj <= 1; dj++)
            {
                if (abs(di) + abs(dj) != 1) continue;
                int ni = i + di, nj = j + dj;
                if (0 <= ni && ni < h && 0 <= nj && nj < w && s[ni][nj] != '#')
                {
                    if (s[ni][nj] == 'x')
                    {
                        if (k == 0) continue;
                        else 
                        {
                            if (deep[ni][nj][k] > deep[i][j][k] + 1)
                            {
                                q.push({ni, nj, k});
                                deep[ni][nj][k] = deep[i][j][k] + 1;
                            }
                        }
                    }
                    else if (s[ni][nj] == 'o')
                    {
                        if (k == 1) continue;
                        else
                        {
                            if (deep[ni][nj][k] > deep[i][j][k] + 1)
                            {
                                q.push({ni, nj, k});
                                deep[ni][nj][k] = deep[i][j][k] + 1;
                            }
                        }
                    }
                    else if (s[ni][nj] == '?')
                    {
                        // cout << "YES";
                        if (deep[ni][nj][(k + 1) % 2] > deep[i][j][k] + 1)
                        {
                            q.push({ni, nj, (k + 1) % 2});
                            deep[ni][nj][(k + 1) % 2] = deep[i][j][k] + 1;
                        }
                    }
                    else
                    {
                        if (deep[ni][nj][k] > deep[i][j][k] + 1)
                        {
                            q.push({ni, nj, k});
                            deep[ni][nj][k] = deep[i][j][k] + 1;
                        }

                    }
                }
            }

        }
    }

    // for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < w; j++)
    //     {
    //         cout << deep[i][j][0] << ", " << deep[i][j][1] << " ";
    //     }
    //     cout << '\n';
    // }

    cout << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);  
    cin.tie(nullptr), cout.tie(nullptr);  
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}