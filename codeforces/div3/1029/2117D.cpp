#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto & e : a) cin >> e;
    ll x = (n * a[n - 1] - a[0]) / (n * n - 1);
    ll y = (a[0] - x ) / n;
    bool f = x >= 0 && y >= 0;
    for (int i = 1; i <= n; ++i)
    {
        if (x * i + y * (n - i + 1) != a[i - 1]) f = false; 
    }
    cout << (f ? "YES" : "NO") << '\n';
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