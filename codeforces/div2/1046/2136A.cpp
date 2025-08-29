#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    c -= a;
    d -= b;
    if (a < b) swap(a, b);
    if (c < d) swap(c, d);

    a -= 2;
    while (b)
    {
        a -= 2;
        b--;
    }

    c -= 2;
    while (d)
    {
        c -= 2;
        d--;
    }
    cout << (a <= 0 && c <= 0 ?"YES":"NO") << '\n';

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