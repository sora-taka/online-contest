#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<ll> p(n), s(n), a(n);
    for (auto & e : p) cin >> e;
    for (auto & e : s) cin >> e;
    for (int i = 0; i < n; ++i) 
    {
        a[i] = lcm(p[i], s[i]);
    }
    bool f = a[0] == p[0] && a[n - 1] == s[n - 1];
    for (int i = 1; i < n; ++i) 
    {
        f &= p[i] == gcd(p[i - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; --i) 
    {
        f &= s[i] == gcd(s[i + 1], a[i]);
    }
    cout << (f ? "YES" : "NO") << '\n';
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