#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);

    for (auto & e : a) cin >> e;
    for (auto & e : b) cin >> e;
    ll sum = 0;
    for (int i = 0; i < n; i++) sum += min(a[i], b[i]);
    while (q--)
    {
        char c;
        int x, v;
        cin >> c >> x >> v;
        sum -= min(a[x - 1], b[x - 1]);
        if (c == 'A')
        {
            a[x - 1] = v;
        }
        else
        {
            b[x - 1] = v;
        }
        sum += min(a[x - 1], b[x - 1]);

        cout << sum << '\n';
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