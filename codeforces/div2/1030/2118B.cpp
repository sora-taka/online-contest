#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    cout << (n - 1) * 2 + 1 << '\n';
    cout << 1 << ' ' << 1 << ' ' << n << '\n';
    int l = 1, mid = 2, r = n;
    for (int i = 2; i <= n; ++i)
    {
        cout << i << ' ' << l << ' ' << mid - 1 << '\n';
        cout << i << ' ' << mid << ' ' << r << '\n';
        mid ++;
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