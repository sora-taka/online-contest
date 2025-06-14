#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int & e : a) cin >> e;
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) if (a[i]) r = i;
    for (int i = n - 1; i >= 0; --i) if (a[i]) l = i;
    if (l == -1 || r - l + 1 <= x) cout << "YES\n";
    else cout << "NO\n";
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