#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n,l, r;
    cin >> n >> l >> r;
    int cnt = 0;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        if (x <= l &&y >= r) cnt++;
    }
    cout << cnt;
}

int main()
{
    ios::sync_with_stdio(false);  
    cin.tie(nullptr), cout.tie(nullptr);  
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}