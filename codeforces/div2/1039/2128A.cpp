#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, c;
    cin >> n >> c;
    vector<ll> a(n);
    for (ll & e : a) cin >> e;
    ranges::sort(a, greater<ll>());
    ll k = 1;
    while(a.back() * k <= c)
    {
        int idx;
        for (int i = 0; i < a.size(); ++i)
        {
            if (a[i] * k <= c) 
            {
                idx = i;
                break;
            }
        }
        a.erase(a.begin() + idx);
        k *= 2;
    }
    cout << a.size() << '\n';
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