#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int cnt = 0;
    vector<pii> v;
    vector g(n + 1, vector(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            if (c == 'g') g[i][j] = 1, cnt++;
            if (c == '.') v.push_back({i, j});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            g[i][j] += g[i - 1][j];
            g[i][j] += g[i][j - 1];
            g[i][j] -= g[i - 1][j - 1];
            // cout << g[i][j] << ' ';
        }
        // cout << '\n';
    }
    int ans = 0;
    for (auto [i, j] : v)
    {
        int x1, y1, x2, y2;
        x1 = max(0, i - k);
        y1 = max(0, j - k);
        x2 = min(n, i + k - 1);
        y2 = min(m, j + k - 1);
        // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
        ans = max(ans, cnt - (g[x2][y2] - g[x1][y2] - g[x2][y1] + g[x1][y1]));
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