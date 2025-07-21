#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int a, x, y;
    cin >> a >> x >> y;
    if (a < min(x, y) || a > max(x, y)) cout << "YES\n";
    else cout << "NO\n";
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