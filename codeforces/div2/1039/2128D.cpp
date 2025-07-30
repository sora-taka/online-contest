#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<ull> p(n), dp(n);
    for (auto & e : p) cin >> e;
    dp[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        if (p[i] > p[i - 1]) dp[i] = dp[i - 1] + 1;
        else dp[i] = dp[i - 1] + i + 1;
    }
    ull sum = 0;
    for (auto e : dp) sum += e;
    cout << sum << '\n';
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