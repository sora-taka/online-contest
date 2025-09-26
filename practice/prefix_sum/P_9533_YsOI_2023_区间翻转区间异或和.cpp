#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

// 分情况讨论，交换是否有影响

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int & e : a) cin >> e;
    partial_sum(a.begin(), a.end(), a.begin(), [](int prev, int curv){
        return prev ^ curv;
    });
    map<int, int> cnts;
    cnts[0] = 1;
    for (int i = 0; i < n; i++) cnts[a[i]]++;
    ll ans = 0;

    for (auto [_, v] : cnts)
    {
        ans += 1ll * v * (v - 1) / 2;
    }
    cout << ans << '\n';
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false); 
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}