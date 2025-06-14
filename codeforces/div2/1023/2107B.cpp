#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    ll n, k;
    string s;
    cin >> n >> k >> s;
    vector<ll> a(n);
    for (ll & e : a) cin >> e;

    vector<int> spi;
    vector<ll> sa;
    ll tot = 0, sum = 0;
    for (int i = 0; i < n; ++ i) 
    {
        tot += a[i];
        sum += a[i];
        if (s[i] == '0')
        {
            spi.push_back(i);
            sa.push_back(sum);
            sum = 0;
        }
    }
    if (spi.empty())
    {
        ll path = 0, maxn = -9e18;
        for (int i = 0; i < n; ++ i) 
        {
            path = max(a[i], path + a[i]);
            maxn = max(maxn, path);
        }
        if (maxn == k)
        {
            cout << "Yes\n";
            for (ll & e : a) cout << e << ' ';
            cout << '\n';
        }
        else cout << "No\n";
    }
    else 
    {
        bool f = true;
        for (auto e : spi) a[e] = -1e18;
        ll path = 0, maxn = -9e18;
        for (int i = 0; i < n; ++ i) 
        {
            path = max(a[i], path + a[i]);
            maxn = max(maxn, path);
        }
        if (maxn == k)
        {
            cout << "Yes\n";
            for (ll & e : a) cout << e << ' ';
            cout << '\n';
        }
        else if (maxn > k)
        {
            cout << "No\n";
        }
        else 
        {
            a[spi[0]] = 0;
            ll pah1 = 0, max1 = 0, pah2 = 0, max2 = 0;
            for (int i = spi[0]; i >= 0; --i)
            {
                pah1 = max(a[i], pah1 + a[i]);
                max1 = max(max1, pah1);
            }
            for (int i = spi[0]; i < (1 >= spi.size()? n : spi[1]); ++i)
            {
                pah2 = max(a[i], pah2 + a[i]);
                max2 = max(max2, pah2);
            }
            a[spi[0]] = tot - ( max1 + max2);
            cout << "Yes\n";
            for (ll & e : a) cout << e << ' ';
            cout << '\n';
        }
    }

}
int main()
{
    ios::sync_with_stdio(0);  
    cin.tie(0), cout.tie(0);  

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}