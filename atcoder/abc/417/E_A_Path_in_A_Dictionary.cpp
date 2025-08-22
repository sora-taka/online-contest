#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    for (auto &v : g) ranges::sort(v);

    
    vector<bool> vis(n, false), bad(n, false);
    vector<int> path;
    vis[x - 1] = true;
    path.push_back(x - 1);
    bool f = false;
    auto bfs = [&](auto &&bfs,int root)
    {
        if (root == y - 1) 
        {
            for (auto & e : path) cout << e + 1 << ' ';
            f = true;
            cout << '\n';
            return;
        }
        for (int e : g[root])
        {
            if (bad[e] || vis[e] || f) continue;
            vis[e] = true;
            path.push_back(e);
            bfs(bfs, e);
            vis[e] = false;
            path.pop_back();
        }
        bad[root] = true;
    };
    bfs(bfs, x - 1);
}

int main()
{
    ios::sync_with_stdio(false);  
    cin.tie(nullptr), cout.tie(nullptr);  
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}