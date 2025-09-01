#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int q;
    cin >> q;
    vector<int> nxt(q + 1);
    nxt[0] = -1;
    for (int i = 1; i <= q; ++i)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x;
            cin >> x;
            nxt[i] = nxt[x];
            nxt[x] = i;
        }
        else
        {
            int x, y;
            cin >> x >> y;
            ll sum_x = 0, sum_y = 0;
            int i = nxt[x], j = nxt[y];
            while (i != y && j != x)
            {
                if (i != -1) sum_x += i, i = nxt[i];
                if (j != -1) sum_y += j, j = nxt[j];
            }
            if (i == y)
            {
                nxt[x] = y;
                cout << sum_x << endl;
            }
            else
            {
                nxt[y] = x;
                cout << sum_y << endl;
            }
        }
        // for (int i = 0; i != -1; i = nxt[i]) cout << i << " ";
        // cout << endl;
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