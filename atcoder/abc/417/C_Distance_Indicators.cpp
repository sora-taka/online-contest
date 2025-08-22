#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int & e : a) cin >> e;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i)
    {
        mp[i + 1 - a[i]].push_back(i);
    }
    ll sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (mp[a[i] + i + 1].size() > 0)
        {
            sum += mp[a[i] + i + 1].end() - ranges::lower_bound(mp[a[i] + i + 1], i);
        }
    }
    // for (auto [k, v] : mp)
    // {
    //     cout << k << ": ";
    //     for (int e : v) cout << e << ' ';
    //     cout << '\n';
    // }
    cout << sum;
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