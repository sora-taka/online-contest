#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    ll l, r;
    cin >> l >> r;
    auto f = [](ll x) -> ll
    {
        ll u = x / 2 + x / 3 + x / 5 + x / 7;
        u -= x / 6 + x / 10 + x / 14 + x / 15 + x / 21 + x / 35;
        u += x / 30 + x / 42 + x / 70 + x / 105;
        u -= x / 210;
        return x - u;
    };
    cout << f(r) - f(l - 1) << '\n';
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