#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    ll a, b;
    cin >> a >> b;
    if (a % 2 == 0 && b % 2 != 0) cout << -1 << '\n';
    else if (a % 2 != 0 && b % 2 != 0) cout << a * b + 1 << '\n';
    else if (a % 2 == 0 && b % 2 == 0) cout << b / 2 * a + 2 << '\n';
    else 
    {
        if (b % 4 == 0) cout << b / 2 * a + 2 << '\n';
        else cout << -1 << '\n';
    }
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