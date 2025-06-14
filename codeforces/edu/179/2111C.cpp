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
    ll ans = 9e18;
    int l = 0, len = 1;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == a[l]) len++;
        else {
            ans = min(ans, 1ll * (n - len) * a[l]);
            l = i;
            len = 1;
        }
    }
    ans = min(ans, 1ll * (n - len) * a[l]);
    cout << ans << '\n';
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