#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int r, x;
    cin >> r >> x;
    if (x == 1 && r >= 1600 && r <= 2999|| x == 2&& r >= 1200 && r <= 2399)
    {
        cout << "Yes";
    }else cout << "No";
}

int main()
{
    ios::sync_with_stdio(0);  
    cin.tie(0), cout.tie(0);  

    int t = 1;
    // cin >> t;    s
    while (t--)
    {
        solve();
    }
    return 0;
}