#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    ll a, b, k;
    cin >> a >> b >> k;
    if (max(a, b) / gcd(a, b) <= k) cout << 1 << '\n';
    else cout << 2 << '\n';
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