#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (a > b) 
    {
        if ((a ^ 1) != b) cout << -1 << '\n';
        else cout << y << '\n';
    }
    else if (a == b)
    {
        cout << 0 << '\n';
    }
    else
    {
        if (x <= y) 
        {
            cout << (b - a) * x << '\n';
        }
        else
        {
            int ans = 0;
            while (a < b)
            {
                if ((a & 1) == 1) ans += x;
                else ans += y;
                a++;
            }
            cout << ans << '\n';
        }
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