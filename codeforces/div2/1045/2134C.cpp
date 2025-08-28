#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll & e : a) cin >> e;
    if (n % 2 == 0) a.push_back(0);
    ll sum = 0;
    for (int i = 1; i < a.size(); i += 2)
    {
        if (a[i] >= a[i - 1] + a[i + 1]) continue;
        ll t = a[i - 1] + a[i + 1] - a[i];
        sum += t;
        a[i + 1] -= min(t, a[i + 1]);
    }
    cout << sum << '\n';
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