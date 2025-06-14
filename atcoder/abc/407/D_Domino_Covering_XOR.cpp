#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

int h, w;
ll ans = 0;
set<ll> st;
vector<vector<ll>> g, k;
vector<vector<bool>> vis;

void dfs(int x, int y, ll path, ll id)
{
    ans = max(ans, path);
    if (st.find(id) != st.end()) return;
    else st.insert(id);
    for (int i = x; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (!vis[i][j] && i + 1 < h && !vis[i + 1][j])
            {
                vis[i][j] = vis[i + 1][j] = true;
                dfs(x, y, path ^ g[i][j] ^ g[i + 1][j], id | k[i][j] | k[i + 1][j]);
                vis[i][j] = vis[i + 1][j] = false;
            }
            if (!vis[i][j] && j + 1 < w && !vis[i][j + 1])
            {
                vis[i][j] = vis[i][j + 1] = true;
                dfs(x, y, path ^ g[i][j] ^ g[i][j + 1], id | k[i][j] | k[i][j + 1]);
                vis[i][j] = vis[i][j + 1] = false;
            }
        }
    }
}

void solve()
{
    cin >> h >> w;
    g = vector(h, vector(w, 0ll));
    k = vector(h, vector(w, 0ll));
    vis = vector(h, vector(w, false));
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cin >> g[i][j];
            ans ^= g[i][j];
            k[i][j] = 1 << (i * (w + 1) + j + 1);
        }
    }
    dfs(0, 0, ans, 0);
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