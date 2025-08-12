#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pii> a(n);
    for (auto &[x, _] : a) cin >> x;
    for (auto &[_, y] : a) cin >> y;
    ll sum = 0;
    for (auto &[x, y] : a) 
    {
        if (y > x) swap(x, y);
        sum += x - y;
    }
    ranges::sort(a, greater<pii>());
    ll minn = 1e18;
    for (int i = 0; i < n - 1; i++) 
    {
        minn = min(minn, 2ll * max(0, a[i].second - a[i + 1].first));
    }
    // ll ans = 0;
    cout << sum + minn << '\n';
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