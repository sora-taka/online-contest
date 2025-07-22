#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), dp(5001, 1e9);
    for (int &e : a) cin >> e, dp[e] = 0;
    for (int i = 5000; i >= 1; --i)
    {
        if (dp[i] != 1e9)
        {
            for (int e : a)
            {
                int k = gcd(e, i);
                dp[k] = min (dp[k], dp[i] + 1);
            }
        }
    }

    int base = a[0], cnt = 0;
    bool f = true;
    for (auto & e : a) base = gcd(base, e);
    for (auto & e : a) cnt += e != base;
    if (cnt != n) cout << cnt << '\n';
    else cout << (n + dp[base] - 1) << '\n';
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