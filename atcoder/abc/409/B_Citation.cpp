#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto & e : a) cin >> e;
    int maxn = 0;
    for (int i = 0; i <= 100; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < n; ++j)
        {
            if (a[j] >= i) cnt++;
        }
        if (cnt >= i) maxn = max(maxn, i);
    }
    cout << maxn;
}

int main()
{
    ios::sync_with_stdio(0);  
    cin.tie(0), cout.tie(0);  
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}