#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<queue<int>> cnt(n + 1);
    vector<int> maxl(n + 1, 0);

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        maxl[i] = maxl[i - 1];
        cnt[a[i]].push(i);
        if (cnt[a[i]].size() == a[i])
        {
            // cout << i << ' ' << cnt[a[i]][cnt[a[i]].size()- a[i]] << ' ';
            maxl[i] = max(maxl[ cnt[ a[i] ].front() - 1] + a[i], maxl[i]);
            cnt[a[i]].pop();
        }
        // cout << maxl[i] << ' ';
        ans = max(ans, maxl[i]);
    }
    // cout << '\n';
    cout << ans << '\n';
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