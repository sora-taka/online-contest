#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int a, b, cnt = 0;
    cin >> a >> b;
    set<int> st;
    for (int i = 1; i <= 6; ++i)
    {
        for (int j = 1; j <= 6; ++j)
        {
            if (i + j >= a || abs(i - j) >= b) cnt++;
        }
    }
    double ans = (double)cnt/ 36;
    cout << fixed << setprecision(13) << ans;
}

int main()
{
    ios::sync_with_stdio(0);  
    cin.tie(0), cout.tie(0);  

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}