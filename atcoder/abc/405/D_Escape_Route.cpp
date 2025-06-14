#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

int h, w;
vector<pii> es;
vector<vector<int>> d;

vector<vector<char>> g, ans;
void b( int x, int y, char ch, int len)
{
    d[x][y] = len;
    ans[x][y] = ch;
}
void bfs()
{
    deque<tuple<int,int>> q;
    for (auto [x0, y0] : es)
    {
        b(x0, y0, 'E', 0);
        q.push_back({x0, y0});
    }
    int len = 0;
    while (!q.empty())
    {
        
        int wtf = q.size();
        while (wtf--)
        {
            auto [x, y] = q.front();
            q.pop_front();

            if (x + 1 < h && g[x + 1][y] != '#' && d[x + 1][y] > len + 1) 
            {
                b(x + 1, y, '^', len + 1);
                q.push_back({x + 1, y});
            }
            
            if (x - 1 >= 0 && g[x - 1][y] != '#' && d[x - 1][y] > len + 1)
            {
                b(x - 1, y, 'v', len + 1);
                q.push_back({x - 1, y});
            }
            
            if (y + 1 < w && g[x][y + 1] != '#' && d[x][y + 1] > len + 1) 
            {
                b(x, y + 1, '<', len + 1);
                q.push_back({x, y + 1});
            }
            
            if (y - 1 >= 0 && g[x][y - 1] != '#' && d[x][y - 1] > len + 1) 
            {
                b(x, y - 1, '>', len + 1);
                q.push_back({x, y - 1});
            }
            
        }
        len++;
    }
    

}

void solve()
{
    cin >> h >> w;
    d = vector<vector<int>>(h, vector<int>(w, int(2e9)));
    g = vector<vector<char>>(h, vector<char>(w));
    ans = vector<vector<char>>(h, vector<char>(w));
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cin >> g[i][j];
            ans[i][j] = g[i][j];
            if (g[i][j] == 'E')
            {
                d[i][j] = 0;
                es.push_back({i, j});
            }
        }
    }

        // vis = vector<vector<int>>(h, vector<int>(w, int(0)));
        bfs();

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);  
    cin.tie(0), cout.tie(0);  

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}