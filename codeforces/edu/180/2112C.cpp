#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e : a) cin >> e;
    ranges::sort(a);
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int l = upper_bound(a.begin() + j + 1, a.end(), a[n - 1] - a[i] - a[j]) - a.begin();
            int r = lower_bound(a.begin() + j + 1, a.end(), a[i] + a[j]) - a.begin() - 1;
            if (l != n && r >= l) ans += r - l + 1;
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