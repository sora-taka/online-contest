#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    if (x > y) swap(a, b), swap(x, y);
    if (a <= b)
    {
        int cnt = 0;
        if (k >= a) cnt += (k - a) / x, k -= cnt * x;
        if (k >= a) cnt++;
        cout << cnt << '\n';
    }
    else
    {
        int cnt = 0;
        if (k >= a) cnt += (k - a) / x, k -= cnt * x;
        if (k >= a) cnt++, k -= x;
        if (k >= b) cnt += (k - b) / y, k -= (k - b) / y * y;
        if (k >= b) cnt++;
        cout << cnt << '\n';
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