#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

int fib[11]{0, 1, 2};

void solve()
{
    int n, m;
    cin >> n >> m;
    int maxn = fib[n] + fib[n - 1], minn = fib[n];
    string ans(m, '0');
    for (int i = 0; i < m; i++)
    {
        int w, l, h;
        cin >> w >> l >> h;
        int maxx = max({w, l, h});
        int minx = min({w, l, h});
        if (minx >= minn && maxx >= maxn) ans[i] = '1';
    }
    cout << ans << '\n';
    
}

int main()
{

    for (int i = 3; i <= 10; ++i) fib[i] = fib[i - 1] + fib[i - 2];
    ios::sync_with_stdio(0);  
    cin.tie(0), cout.tie(0);  
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}