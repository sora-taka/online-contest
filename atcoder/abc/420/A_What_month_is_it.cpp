#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int a, b;
    cin >> a >> b;
    cout << (a + b - 1) % 12 + 1 << '\n';
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