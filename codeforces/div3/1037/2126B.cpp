#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) a[i] += a[i - 1];
    // for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    int last = -1, ans = 0;
    for (int i = k - 1; i <= n; ++i)
    {
        if (i - k + 1 > last && a[i] == a[i - k])
        {
            last = i + 1;
            ans++;
        }
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