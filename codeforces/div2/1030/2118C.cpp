#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const ll mk = 1e18;

void solve()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll & e : a) cin >> e;
    multiset<ll> st;
    int cnt = 0;
    for (auto e : a)
    {
        ll t = 1;
        while (t <= mk)
        {
            if ((t & e) == 0) st.insert(t);
            else cnt++;
            t <<= 1;
        }
    }
    for (auto e : st)
    {
        if (e <= k) cnt++, k -= e;
    }
    cout << cnt << '\n';
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