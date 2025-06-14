#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a * 60 + b > c * 60 + d) cout << "Yes";
    else cout << "No";
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