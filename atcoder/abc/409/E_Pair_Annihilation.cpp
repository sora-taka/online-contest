#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> x(n), d(n);
    vector g(n, vector<pii>());
    for (auto & e : x) cin >> e;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u - 1].push_back({v - 1, w});
        g[v - 1].push_back({u - 1, w});
    }
    queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        d[i] = g[i].size();
        if (d[i] == 1) q.push(i);
    }
    ll ans = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for( auto [v, w] : g[u])
        {
            if (d[v])
            {
                d[v] --;
                d[u] --;
                if (d[v] == 1) q.push(v);
                ans += (long long)abs(x[u]) * w;
                x[v] += x[u];
                x[u] = 0;
            }
        }
    }
    
    cout << ans;
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