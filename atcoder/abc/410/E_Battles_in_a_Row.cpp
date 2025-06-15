#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, h, m;
    cin >> n >> h >> m;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    vector dp(n, vector<int>(h + 1, -1));

    int ans = 0;
    if (h >= a[0]) dp[0][h - a[0]] = m, ans = 1;
    if (m >= b[0]) dp[0][h] = m - b[0], ans = 1;

    for (int i = 1; i < n; ++i)
    {
        for (int j = h; j >= 0; --j)
        {
            if (j + a[i] <= h) dp[i][j] = max(dp[i][j], dp[i - 1][j + a[i]]);
            if (dp[i - 1][j] - b[i] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j] - b[i]);
            if (dp[i][j] != -1) ans = max(ans, i + 1);
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