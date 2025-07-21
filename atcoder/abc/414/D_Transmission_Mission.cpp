#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> x(n);
    for (auto & e : x) cin >> e;
    ranges::sort(x);
    ll l = 0, r = x[n - 1] + 1, mid = l + (r - l) / 2, ans = x[n - 1] + 1;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        int cnt = 0;
        ll up = 0;
        for (auto e: x)
        {
            if (e > up)
            {
                up = e + mid;
                cnt++;
            }
        }
        if (cnt <= m)
        {
            ans = min(mid, ans);
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans;
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