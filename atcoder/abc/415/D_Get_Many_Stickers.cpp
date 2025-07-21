#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<pll> a(m);
    for(auto & [x, y] : a) cin >> x >> y;
    ranges::sort(a, [](pll x, pll y)
    {
        if (x.first - x.second != y.first - y.second) return x.first - x.second < y.first - y.second;
        return x.first < y.first;
    });
    ll cnt = 0;
    for (auto & [x, y] : a)
    {
        // cout << x << ' ' << y << '\n';
        while (n >= x) 
        {
            cnt += (n - x) / (x - y);
            n = x + (n - x) % (x - y);
            if (n >= x) n -= x - y, cnt++;
        }
    }
    cout << cnt << '\n';
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