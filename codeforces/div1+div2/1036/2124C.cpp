#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> b(n);
    for (int & e : b) cin >> e;
    ranges::reverse(b);
    ll x = 1;
    auto lcm = [](ll x, ll y) -> ll { return x * y / gcd(x, y); };
    for (int i = 1; i < n; ++i)
    {
        if (b[i - 1] % b[i] != 0)
        {
            x = lcm(x, b[i] / gcd(b[i - 1], b[i]));
        }
    }
    cout << x << '\n';
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