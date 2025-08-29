#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

void solve()
{
    int n;
    cin >> n;
    vector<pll> a(n);
    for (auto &[x , y] : a) cin >> x >> y;
    ll max_x_p_y = -1e18, max_x_m_y = -1e18;
    for (auto &[x , y] : a)
    {
        max_x_p_y = max(max_x_p_y, x + y);
        max_x_m_y = max(max_x_m_y, x - y);
    }

    ll k = 1'000'000'000;

    ll reply;

    cout << "? U " << k << '\n';
    cout.flush();
    cin >> reply;
    cout << "? U " << k << '\n';
    cout.flush();
    cin >> reply;
    cout << "? R " << k << '\n';
    cout.flush();
    cin >> reply;

    cout << "? R " << k << '\n';
    cout.flush();
    cin >> reply;

    ll x_plus_y = reply - 4 * k + max_x_p_y;

    cout << "? D " << k << '\n';
    cout.flush();
    cin >> reply;
    cout << "? D " << k << '\n';
    cout.flush();
    cin >> reply;
    cout << "? D " << k << '\n';
    cout.flush();
    cin >> reply;

    cout << "? D " << k << '\n';
    cout.flush();
    cin >> reply;

    ll x_minus_y = reply - 4 * k + max_x_m_y;

    cout << "! " << (x_plus_y + x_minus_y) / 2 << ' ' << (x_plus_y - x_minus_y) / 2 << '\n';
    cout.flush();

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