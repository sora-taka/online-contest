#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<pii> pos(n);
    for (auto &[x, y] : pos) cin >> x >> y;
    int a = -2e9, b = -2e9, c = 2e9, d = 2e9;
    for (auto [x, y] : pos)
    {
        a = max(a, x);
        b = max(b, y);
        c = min(c, x);
        d = min(d, y);

    }
    cout << max((a - c + 1) / 2, (b - d + 1) / 2) << endl;
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