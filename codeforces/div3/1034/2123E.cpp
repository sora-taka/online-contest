#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> cnt(n + 1), d(n + 2);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    // 0
    d[1] += 1;
    d[n - cnt[0] + 1] -= 1;

    for (int i = 1; i <= n; ++i)
    {
        if (cnt[i - 1] == 0) break;
        d[i] += 1;
        d[n - cnt[i] + 1] -= 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        d[i] += d[i - 1];
        // cout << d[i] << ' ';
    }
    d[0] = 1;
    for (int i = n; i >= 0; --i)
    {
        cout << d[i] << ' ';
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