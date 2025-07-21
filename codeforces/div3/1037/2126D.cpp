#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<tuple<int, int, int>> a(n);
    for (auto &[l, r, f] : a) cin >> l >> r >> f;
    ranges::sort(a, [](auto x, auto y){ 
        if (get<2>(x) != get<2>(y)) return get<2>(x) < get<2>(y);
        if (get<0>(x) != get<0>(y)) return get<0>(x) < get<0>(y);
        return get<1>(x) < get<1>(y);
    });
    int maxn = k, minn = k;
    for (auto &[l, r, f] : a)
    {
        // cout << l << ' ' << r << ' ' << f << '\n';
        if (l <= minn && minn <= r || l <= maxn && maxn <= r) 
        {
            maxn = max(maxn, f);
            minn = min(minn, f);
        }
    }
    cout << maxn << '\n';
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