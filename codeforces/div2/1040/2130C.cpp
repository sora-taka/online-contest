#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    using t3i = tuple<int, int, int>;
    vector<t3i> a(n);
    for (int i = 0; i < n; ++i)
    {
        auto & [u, v, idx] = a[i];
        cin >> u >> v;
        idx = i + 1;
    }
    ranges::sort(a, [](t3i x, t3i y)
    {
        if (get<0>(x) != get<0>(y)) return get<0>(x) < get<0>(y);
        return get<1>(x) > get<1>(y);
    });

    vector<int> ans;
    int lu = 0, lv = 0;
    for (auto [u, v, idx] : a)
    {
        if (u != lu) ans.push_back(idx);
        lu = u;
    }
    ranges::sort(ans);
    cout << ans.size() << '\n';
    for (int e : ans) cout << e << ' ';
    cout << '\n';

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