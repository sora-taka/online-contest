#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector g(n, vector<pii>());
    for (int i = 0; i < m; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        g[a].push_back({b, w});
    }
    set<pii> st;
    int ans = -1;
    auto dfs = [&](this auto &self, int a, int path) -> void
    {

        for (auto & [b, w] : g[a])
        {
            if (b == n - 1) 
            {
                if (ans != -1) ans = min(ans, path ^ w);
                else ans = path ^ w;
            }
            if (st.find({b, path ^ w}) == st.end()) 
            {
                st.insert({b, path ^ w});
                self (b, path ^ w);
            }
            
        }
    };
    dfs(0, 0);
    cout << ans << ' ';
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