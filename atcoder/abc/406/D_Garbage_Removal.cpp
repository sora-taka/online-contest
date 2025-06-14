#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int H, W, n;
    cin >> H >> W >> n;
    vector<set<int>> h(H + 1), w(W + 1);
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        h[x].insert(y);
        w[y].insert(x);
    }
    int Q;
    cin >> Q;
    while (Q--)
    {
        int op, q;
        cin >> op >> q;
        if (op == 1)
        {
            cout << h[q].size() << '\n';
            for (auto e : h[q])
            {
                w[e].erase(q);
            }
            h[q].clear();
        }
        else 
        {
            cout << w[q].size() << '\n';
            for (auto e : w[q])
            {
                h[e].erase(q);
            }
            w[q].clear();
        }
    }
    
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