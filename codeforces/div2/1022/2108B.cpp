#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, x;
    cin >> n >> x;
    if (n == 1 && x == 0) 
    {
        cout << -1 << '\n';
        return;
    }
    if (n == 1)
    {
        cout << x << '\n';
        return;
    }
    if (n == 2)
    {
        int cnt = 0, t = x;
        while (t)
        {
            t = t & (t - 1);
            cnt++;
        }
        if (cnt == 0) cout << 2 << '\n';
        else if (cnt == 1)
        {
            if (x - 1 > 0) cout << (x + 2) << '\n';
            else cout << 5 << '\n';
        }
        else cout << x << '\n';
        return ;
    }
    if (x == 0)
    {
        if (n % 2 == 0) cout << n << '\n';
        else cout << n + 3 << '\n';
        return ;
    }

    int cnt = 0, t = x;
    while (t)
    {
        t = t & (t - 1);
        cnt++;
    }
    if (x == 1)
    {
        if (n % 2 == 0) cout << n + 3<< '\n';
        else cout << n << '\n';
    }
    else if (cnt >= n) cout << x << '\n';
    else if ((n - cnt) % 2 == 0 )  cout << x + n - cnt<< '\n';
    else cout << x + n - cnt + 1 << '\n';
}

int main()
{
    // Fast I/O optimization
    ios::sync_with_stdio(0);  // Disable synchronization with C stdio
    cin.tie(0), cout.tie(0);  // Untie cin and cout for faster I/O

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}