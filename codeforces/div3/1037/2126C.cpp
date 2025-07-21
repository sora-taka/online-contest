#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int &e : h) cin >> e;
    bool f = true;
    int cur = h[k - 1], w = 1;
    ranges::sort(h);
    for (int i = 0; i < n; ++i)
    {
        // cout << i << ' ' << cur << ' ' << w << '\n';
        if (h[i] > cur) 
        {
            w += h[i] - cur;
            if (w - 1 > cur) f = false;
            cur = h[i];
        }
        if (w > cur) f = false;
    }
    cout << (f ? "YES": "NO") << '\n';
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