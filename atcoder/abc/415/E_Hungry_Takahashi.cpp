#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int h, w;
    cin >> h >> w;
    vector a(h, vector(w, 0ll)), dp(h, vector(w, 0ll));
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cin >> a[i][j];
        }
    }
    vector<ll> p(h + w - 1);
    for (ll &e : p) cin >> e;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            a[i][j] -= p[i + j];
        }
    }

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (i == 0 && j == 0) continue;
            a[i][j] += max(a[i - 1][j])
        }
    }
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