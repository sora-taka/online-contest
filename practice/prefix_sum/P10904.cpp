#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector a(1'000'001, 0), b(1'000'001, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x < 0) a[-x]++;
        else b[x]++;
    }
    partial_sum(a.begin(), a.end(), a.begin());
    partial_sum(b.begin(), b.end(), b.begin());
    // for (int i = 0; i < n; i++) cout << a[i] << ' ';
    // cout << '\n';
    // for (int i = 0; i < n; i++) cout << b[i] << ' ';
    // cout << '\n';
    int ans = 0;
    for (auto i = 0uz; i <= m; i++)
    {
        int t = 0;
        if (i < a.size()) t += a[i]; else t += a.back();
        if (i * 2 <= m)
        {
            if (m - i * 2 < b.size()) t += b[m - i * 2]; else t += b.back();
        }
        ans = max(ans, t);
    }
    for (auto i = 0uz; i <= m; i++)
    {
        int t = 0;
        if (i < b.size()) t += b[i]; else t += b.back();
        if (i * 2 <= m)
        {
            if (m - i * 2 < a.size()) t += a[m - i * 2]; else t += a.back();
        }
        ans = max(ans, t);
    }
    cout << ans << '\n';
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