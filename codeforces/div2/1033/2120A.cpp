#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    if (l3 == l1 && b3 + b2 + b1 == l1 || b1 == b3 && l3 + l2 + l1 == b1
        || l2 == l3 && l1 + l2 == b1 && b2 + b3 == b1
        || b2 == b3 && b1 + b2 == l1 && l3 + l2 == l1) cout << "YES\n";
    else cout << "NO\n";
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