#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    using t3i = tuple<int, int, int>;
    vector<t3i> vt(n);
    for (int i = 0; i < n; ++i)
    {
        auto &[x, y, idx] = vt[i];
        cin >> x >> y;
        idx = i + 1;
    }
    ranges::sort(vt, [](t3i x, t3i y) {return get<0>(x) > get<0>(y);});
    auto cmp = [](t3i x, t3i y){return get<1>(x) > get<1>(y);};
    sort(vt.begin(), vt.begin() + n / 2, cmp);
    sort(vt.begin() + n / 2, vt.end(), cmp);
    int cnt = 0;
    vector<pii> ans;
    int il = 0, ir = n / 2 - 1, jl = n / 2, jr = n - 1;
    for (int i = 0; i < n / 2; ++i)
    {
        if (get<1>(vt[il]) > get<1>(vt[jl]))
        {
            ans.push_back({get<2>(vt[il]), get<2>(vt[jr])});
            cnt += get<1>(vt[il]) - get<1>(vt[jr]) + get<0>(vt[il]) - get<0>(vt[jr]);
            il++;
            jr--;
        }
        else if (get<1>(vt[il]) < get<1>(vt[jl]))
        {
            ans.push_back({get<2>(vt[ir]), get<2>(vt[jl])});
            cnt += get<1>(vt[jl]) - get<1>(vt[ir]) + get<0>(vt[ir]) - get<0>(vt[jl]);
            jl++;
            ir--;
        }
        else if (get<1>(vt[ir]) < get<1>(vt[jr]))
        {
            ans.push_back({get<2>(vt[ir]), get<2>(vt[jl])});
            cnt += get<1>(vt[jl]) - get<1>(vt[ir]) + get<0>(vt[ir]) - get<0>(vt[jl]);
            jl++;
            ir--;   
        }
        else
        {
            ans.push_back({get<2>(vt[il]), get<2>(vt[jr])});
            cnt += get<1>(vt[il]) - get<1>(vt[jr]) + get<0>(vt[il]) - get<0>(vt[jr]);
            il++;
            jr--;
        }
    }
    // cout << cnt << '\n';
    for (auto [a, b] : ans) cout << a << ' ' << b <<'\n';
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