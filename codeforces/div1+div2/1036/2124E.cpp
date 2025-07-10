#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll& e : a) cin >> e;

    int ans = -1, pos;
    ll l = 0, r = 0, diff = 9e18, x, y;
    for (ll& e : a) r += e;
    for (int i = 0; i < n; ++i)
    {
        l += a[i], r -= a[i];
        if (l == r) 
        {
            ans = 1;
            break;
        }
        if (l % 2 == r % 2)
        {
            ans = 2;
            if (abs(r - l) < diff) 
            {
                diff = abs(r - l);
                x = l, y = r;
                pos = i;
            }
        }
    }
    if (ans == -1) cout << -1 << '\n';
    else if (ans == 1)
    {
        cout << 1 << '\n';
        for (ll e : a) cout << e << ' ';
        cout << '\n';
    }
    else if (ans == 2) 
    {
        // cout << x << ' ' << y << ' ' << diff << ' ' << pos;
        vector t = a;
        ll sum = 0, cnt = 0;
        if (x > y) for (int i = 0; i <= pos; ++i)
        {
            if (cnt == 2) break;
            if (sum + a[i] < diff / 2) sum += a[i], t[i] = 0;
            else if (sum + a[i] == diff / 2)
            {
                sum = 0;
                t[i] = 0;
                cnt++;
            }
            else
            {
                t[i] = a[i] - (diff / 2 - sum);
                sum = 0;
                cnt++;
            }
        }
        else for (int i = pos + 1; i < n; ++i)
        {
            if (cnt == 2) break;
            if (sum + a[i] < diff / 2) sum += a[i], t[i] = 0;
            else if (sum + a[i] == diff / 2)
            {
                sum = 0;
                t[i] = 0;
                cnt++;
            }
            else
            {
                t[i] = a[i] - (diff / 2 - sum);
                sum = 0;
                cnt++;
            }
        }
        if (cnt == 2)
        {
            cout << 2 << '\n';
            for (ll e : t) cout << e << ' ';
            cout << '\n';
            for (int i = 0; i < n; ++i) cout << a[i] - t[i] << ' ';
            cout << '\n';
        }
        else cout << -1 << '\n';
    }
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