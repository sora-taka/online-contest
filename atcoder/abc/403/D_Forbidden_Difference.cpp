#include <bits/stdc++.h>

#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

void solve()
{
    int n, d;
    cin >> n >> d;
    vector<ll> a(1'000'001, 0);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    if (d == 0)
    {
        ll sum = 0;
        for (int i = 0; i <= 1'000'000; ++i)
        {

            if (a[i] >= 1)
                sum += a[i] - 1;
        }
        cout << sum;
        return;
    }
    vector<vector<ll>> mp(1'000'001);
    for (int i = 0; i < d; ++i)
    {
        int path = i;
        if (a[i] == 0)
            path = -1;
        else
            mp[i].push_back(a[i]);

        for (int j = i + d; j <= 1'000'000; j += d)
        {
            // cout << j << ' ' << " paht " << path << '\n';
            if (a[j] == 0)
                path = -1;
            else if (path == -1)
            {
                path = j;
                mp[path].push_back(a[j]);
            }
            else
            {
                mp[path].push_back(a[j]);
            }
        }
    }

    ll sum = 0;
    for (int i = 0; i <= 1'000'000; ++i)
    {
        int len = mp[i].size();
        if (len >= 2)
        {

            // cout << i << " : ";
            // for (auto & e : mp[i]) cout << e << ' ';
            // cout << '\n';
            vector<vector<ll>> dp(len, vector<ll>(2));
            dp[0][0] = mp[i][0];
            dp[0][1] = 0;
            for (int j = 1; j < len; j++)
            {
                dp[j][0] = mp[i][j] + min(dp[j - 1][0], dp[j - 1][1]);
                dp[j][1] = dp[j - 1][0];
            }
            sum += min(dp[len - 1][0], dp[len - 1][1]);
        }
    }
    cout << sum << '\n';
}

int main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}