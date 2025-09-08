#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    
    bool f = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int cnt = 0;
            if (g[i][j] == '#')
            {
                if (i - 1 >= 0 && g[i - 1][j] == '#') cnt++;
                if (i + 1 < n && g[i + 1][j] == '#') cnt++;
                if (j - 1 >= 0 && g[i][j - 1] == '#') cnt++;
                if (j + 1 < m && g[i][j + 1] == '#') cnt++;
                if (cnt != 2 && cnt != 4) f = false;
            }
        }
    }
    cout << (f ? "Yes" : "No") << endl;
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