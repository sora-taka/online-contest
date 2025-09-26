#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

// l1 <= r1 < l2 <= r2
// 1 <= n <= 1e3
// 首先 1e3 考虑 n^2logn, 然后多个位置考虑枚举中间

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    partial_sum(a.begin(), a.end(), a.begin());

    set<ll> s; 
    ll ans = numeric_limits<ll>::max();
    for (int r1 = n; r1 >= 1; r1--)
    {
        int l2 = r1 + 1;
        for (int r2 = l2; r2 <= n; r2++)
        {
            ll sum2 = a[r2] - a[l2 - 1];
            s.insert(sum2);
        }
        for (int l1 = 1; l1 <= r1; l1++)
        {
            ll sum1 = a[r1] - a[l1 - 1];
            auto it = s.lower_bound(sum1);
            if (it != s.end()) ans = min(ans, abs(sum1 - *it));
            if (it != s.begin()) ans = min(ans, abs(sum1 - *prev(it)));
        }
    }
    cout << ans << '\n';
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false); 
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}