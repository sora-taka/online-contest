#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    ll x, v = 1;
    cin >> x;
    int cnt = 2;
    while (v < x) v = v * 2 + 1, cnt+= 2;
    cout << cnt + 1 << '\n';
}

int main()
{
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