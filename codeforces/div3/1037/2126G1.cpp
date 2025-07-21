#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto & e : a) cin >> e;
    ll sum = 0;
    vector g(n, vector<pii>());
    vector col(n, map<int, int>());
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
        if (a[u] != a[v]) sum += c;
    }
    vector upd(n, map<int, int>());

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