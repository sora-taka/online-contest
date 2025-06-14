#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;


int n, m;
ll ans = 9e18;
vector<ll> cost;
vector<vector<bool>> g;

void dfs(int pos, vector<int> &path, ll c)
{
    if (c >= ans) return;
    // for (int j = 1; j <= m; ++j)
    // {
    //     cout << path[j] << " \n"[j == m];
    // }

    for (int i = pos; i <= n * 2; ++i) 
    {
        bool f = true;
        for (int j = 1; j <= m; ++j)
        {
            path[j] += g[(i - 1) % n + 1][j];
            f = f && path[j] >= 2;
        }
        if (!f) dfs(i + 1, path, c + cost[(i - 1) % n + 1]);
        else ans = min(ans, c + cost[(i - 1) % n + 1]);
        for (int j = 1; j <= m; ++j)
        {
            path[j] -= g[(i - 1) % n + 1][j];
        }
    }
}
void solve()
{

    cin >> n >> m;
    cost = vector<ll> (2 * n + 1);
    g = vector<vector<bool>>(n + 1, vector<bool>(m + 1));
    for (int i = 1; i <= n; ++i) cin >> cost[i];
    for (int i = n + 1; i <= n + n; ++i) cost[i] = cost[i - n];
    for (int i = 1; i <= m; ++i)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int a;
            cin >> a;
            g[a][i] = true;
        }
    }
    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 1; j <= m; ++j) cout << g[i][j] << " \n"[j == m];
    // }
    vector<int> p(m + 1);
    dfs(1, p, 0);
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