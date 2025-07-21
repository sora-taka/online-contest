#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    s = '0' + s;
    int len = s.size();
    vector<int> vis(len);

    vis[len - 1] = s[len - 1] == '0';
    for (int i = len - 1; i >= 1; --i)
    {
        if (vis[i])
        {
            // cout << i << " : ";
            for (int j = 0; j < n; ++j)
            {
                int t = 1;
                if ((i & (t << j)) && s[(i & ~(t << j))] == '0')
                {
                    // cout << (i & ~(t << j)) << ' ';
                    // cout << j << ' ';
                    vis[(i & ~(t << j))] = true;
                }
            }

        }
    }
    // cout << '\n';
    // for (int e : vis) cout << e << ' ';

    cout << (vis[0] ? "Yes" : "No") << '\n';

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