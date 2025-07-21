#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i] >> d[i];
    ll cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > c[i]) cnt += a[i] - c[i];
        if (b[i] > d[i]) 
        {
            cnt += min(a[i], c[i]);
            cnt += b[i] - d[i];
        }
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