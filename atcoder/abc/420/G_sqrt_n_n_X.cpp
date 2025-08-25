#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    ll x;
    cin >> x;

    ll t = 4 * x - 1;
    vector<ll> d;
    ll ab = abs(t);

    for (ll i = 1; i * i <= ab; i++)
    {
        if (ab % i == 0)
        {
            d.push_back(i);
            if (i != ab / i) d.push_back(ab / i);
            d.push_back(-i);
            if (i != ab / i) d.push_back(-ab / i);
        }
    }

    set<ll> ans;

    for (ll a : d)
    {
        if (t % a != 0) continue;
        ll b = t / a;

        if ((a + b) % 4 != 0) continue;

        ll m = (a + b) / 4;
        if (m < 0) continue;

        ll k = (b - a) / 2;

        if ((k - 1) % 2 == 0)
        {
            ll n = (k - 1) / 2;
            ll v = n * n + n + x;
            if (v >= 0)
            {
                ll sq = sqrt(v);
                if (sq * sq == v) ans.insert(n);
            }
        }

        if ((-k - 1) % 2 == 0)
        {
            ll n = (-k - 1) / 2;
            ll v = n * n + n + x;
            if (v >= 0)
            {
                ll sq = sqrt(v);
                if (sq * sq == v) ans.insert(n);
            }
        }
    }

    cout << ans.size() << '\n';
    for (ll n : ans) cout << n << ' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}