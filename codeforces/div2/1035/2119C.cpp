#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
using pii = pair<int, int>;

void solve()
{
    ull n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n % 2 == 0)
    {
        ull x = 2;
        while (x <= l) x <<= 1;
        if (n == 2 || x > r)
        {
            cout << -1 << '\n';
        }
        else
        {
           if (k >= n - 1) cout << x << '\n';
           else cout << l << '\n';
        }
    }
    else
    {
        cout << l << '\n';
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