#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = 0;
    ll m = min({a, b, c});
    ans += m;
    a -= m, b -= m, c -= m;
    // cout << a<< ' ' << b << ' ' << c << '\n';
    if (a != 0 && c != 0) 
    {
        if (a > c)
        {
            ll t = a - c;
            a -= t;
            m = min(a, t);
            a -= m, c -= m;
            ans += m;
        }
        else if (c > a)
        {
            ll t = c - a;
            c -= t;
            m = min(c, t);
            a -= m, c -= m;
            ans += m;
        }
        // cout << a<< ' ' << b << ' ' << c << '\n';

        ans += a / 3 * 2 + (a % 3 == 2);
    }
    cout << ans << '\n';
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