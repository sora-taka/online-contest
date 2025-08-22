#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    ll n;
    cin >> n;
    ll f = 1;
    vector<ll> ans;
    while (n / f)
    {
        f *= 10;
        if (n % (f + 1) == 0)
        {
            ans.push_back(n / (f + 1));
        }

    }
    ranges::sort(ans);
    if (ans.size() == 0) cout << 0;
    else
    {
        cout << ans.size() << '\n';
        for (auto x : ans) cout << ' ' << x;
    }
    cout << '\n';
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