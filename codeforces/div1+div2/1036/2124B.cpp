#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int & e : a) cin >> e;
    if (n == 2)
    {
        cout << a[0] + min(a[0], a[1]) << '\n';
    }
    else 
    {

        int ans = a[0] + a[1];
        if (a[2] + a[1] > a[0]) ans = min(ans, a[0] * 2);
        cout << ans << '\n';
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