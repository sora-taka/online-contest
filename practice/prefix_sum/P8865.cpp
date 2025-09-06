#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, m, c, f;
    cin >> n >> m >> c >> f;
    vector<string> g(n);
    for (auto &i : g) cin >> i;
    vector a(n, vector(m, 0));
    for (auto i = 0uz; i < n; i++)
    {
        for (auto j = 0uz; j < m; j++)
        {   
            a[i][j] = g[i][j] == '0' ? 1 : 0;
        }
    }
    for (auto i = 0uz; i < n; i++)
    {
        for (int j = m - 2; j >= 0; j--)
        {
            if (a[i][j] >= 1) a[i][j] += a[i][j + 1];   
        }
    }
    for (auto i = 0uz; i < n; i++)
    {
        for (auto j = 0uz; j < m; j++)
        {   
            a[i][j] -= 1;
        }
    }
    for (auto i = 0uz; i < n; i++)
    {
        for (auto j = 0uz; j < m; j++)
        {   
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);  
    cin.tie(nullptr), cout.tie(nullptr);  
    int t = 1, id;
    cin >> t >> id;
    while (t--)
    {
        solve();
    }
    return 0;
}