#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll & e : a) cin >> e;
    ranges::sort(a, greater<ll>());
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (m == 0) break;
        ans += a[i] * m;
        m--;
    }
    cout << ans << '\n';
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