#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int h, w;
    cin >> h >> w;
    vector g(h + 1, vector(w + 1, 0));
    for (int i = 1; i <= h; ++i)
    {
        for (int j = 1; j <= w; ++j)
        {
            char c; cin >> c;
            if (c == '#') g[i][j] = 1;
        }
    }
    for (int i = 1; i <= h; ++i)
    {
        for (int j = 1; j <= w; ++j)
        {
            if (i - 1 > 0) g[i][j] += g[i - 1][j];
            if (j - 1 > 0) g[i][j] += g[i][j - 1];
            if (i - 1 > 0 && j - 1 > 0) g[i][j] -= g[i - 1][j - 1];
        }
    }
    for (int i = 0; i <= h; ++i)
    {
        for (int j = 0; j <= w; ++j)
        {
            cout << g[i][j] << ' ';
        }
        cout << '\n';
    }
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