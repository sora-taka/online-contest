#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, s;
    cin >> n >> s;
    int cnt = 0;
    while (n--)
    {
        int dx, dy, x, y;
        cin >> dx >> dy >> x >> y;
        cnt += dx / dy == 1 && x == y || y == -x + s; 
    }
    cout << cnt << '\n';
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