#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector g(n, vector<int>()); 
    for (int i = 0; i < n - 1; ++ i) 
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    } 
    g[0].push_back(-1);
    bool f = true;
    int a = -1, b = -1, c = -1;
    auto dfs = [&](this auto self, int p, int r, int d, int lr) -> void{

        if (g[r].size() >= 3)
        {
            if (lr == 0 && g[r].size() == 3) {
                int x, y;
                for (auto e : g[r]) if (e != p) x = e;
                for (auto e : g[r]) if (e != p && e != x) y = e;
                self(r, x, d + 1, -1);
                self(r, y, d + 1, +1);
                a = d;
            }
            else f = false;
        } 
        else
        {
            if (lr == 0) a = d;
            if (lr == -1) b = d;
            if (lr == 1) c = d;
            for (auto e : g[r])
            {
                if (e != p) self(r, e, d + 1, lr);
            }
        }

    };
    dfs(-1, 0, 0, 0);
    ll ans = 0;
    
    if (!f) ans = 0;
    else if (b == -1 && c == -1)
    {
        ans = 1;
        for (int i = 0; i <= a; ++i) ans = ans * 2 % mod;
    }
    else if (b == c)
    {
        ans = 1;
        for (int i = 0; i <= a; ++i) ans = ans * 2 % mod;
        ans = ans * 2 % mod;
    }
    else 
    {
        ans = 1;
        for (int i = 0; i <= a; ++i) ans = ans * 2 % mod;
        for (int i = 0; i < max(b-a, c-a) - min(b-a, c-a) - 1; ++i) ans = ans * 2 % mod;
        ans = ans * 3 % mod;
    }

    cout << ans << '\n';
    // cout << a << ' ' << b << ' ' << c << '\n';
}

int main()
{
    ios::sync_with_stdio(0);  
    cin.tie(0), cout.tie(0);  
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}