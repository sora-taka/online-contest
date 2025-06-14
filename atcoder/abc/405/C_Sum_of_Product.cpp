#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n + 1), a(n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        a[i] = v[i] + a[i - 1];
    }
    for (int i = 1; i <= n; ++i)
    {
        ans += v[i] * (a[n] - a[i]);
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