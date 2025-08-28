#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll & e : a) cin >> e;
    if (k % 2 != 0)
    {
        for (ll e : a)
        {
            if (e % 2 == 0) cout << e << " ";
            else cout << e + k << ' ';
        }
    }
    else
    {
        for (ll e : a)
        {
            ll x = e % (k + 1);
           cout << e + x * k << ' ';
        }
    }
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