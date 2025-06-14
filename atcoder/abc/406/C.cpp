#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector <int> q(n), u, d;
    for (auto &e : q) cin >> e;
    for (int i = 1; i < n - 1; ++i)
    {
        if (q[i] > q[i - 1] && q[i] > q[i + 1]) u.push_back(i);
        if (q[i] < q[i - 1] && q[i] < q[i + 1]) d.push_back(i);
    }
    if (u.empty() || d.empty())
    {
        cout << 0;
        return ;
    }

    int ui = 0, di = 0, l = 0, r;
    if (d[0] < u[0]) 
    {
        l = d[0];
        di++;
    }
    ll ans = 0;
    while (ui < u.size() && di < d.size())
    {
        int bl = u[ui] - 1;
        int br = d[di] + 1;
        if (ui + 1 < u.size()) 
        {
            r = u[ui + 1];
            ans += 1ll * (bl - l + 1) * (r - br + 1);
            l = d[di];
            ui ++;
            di++;
        }
        else
        {
            r = br;
            while (r < n - 1 && q[r + 1] > q[r]) r++;
            ans += 1ll * (bl - l + 1) * (r - br + 1);
            break;            
        }
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