#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> b(n + 1), x(q + 1), ans(q + 1);
    for (int j = 1; j <= q; ++j)
    {
        cin >> x[j];
        if (x[j] >= 1) b[x[j]] += 1, ans[j] = x[j];
        else 
        {
            int idx = 1;
            for (int i = 1; i <= n; ++i)
            {
                if (b[i] < b[idx]) idx = i;
            }
            b[idx] += 1;
            ans[j] = idx;
        }       
    }
    for (int i = 1; i <= q; ++i) cout << ans[i] << ' ';
        
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