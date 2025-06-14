#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    ll n, m, p, q;
    cin >> n >> m >> p >> q;
    bool f = false;
    if (n == p && m == q) f = 1;
    else if (p > n / 2)
    {
        if (n % 2 == 0)
        {
            if ((n - 2 - p + 1) == 0) f = m == q;
            else f = (m - q) %  (n - 2 - p + 1) == 0;
        }
        else 
        {
            f = (n - 1 - p + 1) != 0 && (m - q) %  (n - 1 - p + 1) == 0;
        }
    }
    else if (p % 2 != 0 && m % n == 0)
    {
        f = p * m / n == q;
    }
    else 
    {
       int xy = q * 2 / p;
       if (n % 2 == 0) f = n / 2 * xy == m;
       else f = 1;
    }
    if (f) cout << "YES\n";
    else cout << "NO\n";
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