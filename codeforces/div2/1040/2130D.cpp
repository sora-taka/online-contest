#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<ll> p(n), mp(n + 1);
    for (ll & e : p) cin >> e;
    for (ll i = 0; i < n; ++i) mp[p[i]] = i;
    ll sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        ll idx = mp[i], x = p[idx], y = 2 * n - x;
        ll o = 0, c = 0;
        for (int i = 0; i < idx; ++i)
        {
            if (p[i] > x) o ++;
            if (p[i] > y) c ++;
        }
        for (int i = idx + 1; i < n; ++i)
        {
            if (p[i] < x) o ++;
            if (p[i] < y) c ++;
        }
        sum += min(o, c);
        if (c < o) p[idx] = y;
    }
    cout << sum / 2 << '\n';
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