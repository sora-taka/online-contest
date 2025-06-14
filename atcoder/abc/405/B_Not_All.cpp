#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto & e : v) cin >> e;
    int cnt = 0, ans = n;
    for (int i = 0; i < n; ++i)
    {

            set<int> st;
            for (int k = 0; k <= i; ++k)
            {
                st.insert(v[k]);
            }
            if (st.size() < m) ans = min(n - (i + 1), ans);

    }
    cout << ans;
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