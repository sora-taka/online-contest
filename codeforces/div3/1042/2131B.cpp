#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    if (n == 2) cout << -1 << ' ' << 2 << '\n';
    else
    {
        for (int i = 0; i < n; ++i)
        {
            if (i % 2 == 0) cout << -1 << ' ';
            else if (i == n - 1) cout << 2 << ' ';
            else cout << 3 << ' ';
        }
        cout << '\n';
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