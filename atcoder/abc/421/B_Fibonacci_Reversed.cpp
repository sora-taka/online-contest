#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int x, y;
    cin >> x >> y;
    vector<ll> a(10);
    a[0] = x;
    a[1] = y;
    auto rev = [] (ll s) -> ll
    {
        ll res = 0;
        while (s)
        {
            res *= 10;
            res += s % 10;
            s /= 10;
        }
        return res;
    };
    for (int i = 2; i < 10; ++i)
    {
        a[i] = rev(a[i - 1] + a[i - 2]);
    }
    cout << a[9];
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