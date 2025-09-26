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
    vector a(n, vector(m, 0ll)), b(n, vector(m, 0ll)), b1(n, vector(m, 0ll)), b2(n, vector(m, 0ll));
    for (auto i = 0uz; i < n; i++)
    {
        for (auto j = 0uz; j < m; j++)
        {   
            a[i][j] = g[i][j] == '0' ? 1 : 0;
            b[i][j] = g[i][j] == '0' ? 1 : 0;
            b1[i][j] = b2[i][j] = b[i][j];
        }
    }
    for (auto i = 0uz; i < n; i++)
    {
        for (int j = m - 2; j >= 0; j--)
        {
            if (a[i][j] >= 1) a[i][j] += a[i][j + 1];  
            if (b[i][j] >= 1) b[i][j] += b[i][j + 1];  
        }
    }
    for (auto i = 0uz; i < n; i++)
    {
        for (auto j = 0uz; j < m; j++)
        {   
            a[i][j] -= 1;
            b[i][j] -= 1;
            b1[i][j] = b[i][j];
        }
    }
    for (auto j = 0uz; j < m; j++)
    {
        for (int i = n - 2; i >= 0; --i)
        {
            if (a[i][j] >= 0 && a[i + 1][j] >= 0) a[i][j] += a[i + 1][j];  
        }
    }
    for (auto j = 0uz; j < m; j++)
    {
        for (int i = n - 2; i >= 0; --i)
        {
            if (b2[i][j] >= 1 && b2[i + 1][j] >= 1) b2[i][j] += b2[i + 1][j];
            if (b1[i][j] >= 1 && b2[i + 1][j] >= 1) b1[i][j] *= b2[i + 1][j];
        
        }
    }

    for (auto j = 0uz; j < m; j++)
    {
        bool f = false;
        for (int i = n - 1; i >= 0; --i)
        {
            if (b1[i][j] >= 0)
            {
                if (f)
                {
                    b1[i][j] += b1[i + 1][j];  
                }
                else 
                {
                    b1[i][j] = 0;
                    f = true;
                }
            }
            else f = false;
        }
    }

    // for (auto i = 0uz; i < n; i++)
    // {
    //     for (auto j = 0uz; j < m; j++)
    //     {   
    //         cout << b[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    const ll MOD = 998244353;
    ll ans_a = 0, ans_b = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {   
            if (a[i][j] >= 0 && a[i + 1][j] >= 0 && a[i + 2][j] >= 0)
            {
                ans_a = (ans_a + (a[i][j] - a[i + 1][j]) * a[i + 2][j] % MOD) % MOD;
                // cout << (a[i][j] - a[i + 1][j]) * a[i + 2][j] << '\n';
            }
        }
    }
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {   
            if (b[i][j] >= 0 && b[i + 1][j] >= 0 && b[i + 2][j] >= 0 && b[i + 3][j] >= 0) 
            {
                ans_b = (ans_b + b[i][j] * b1[i + 2][j] % MOD) % MOD;
            }
        }
    }
    cout << ans_a * c << ' ' << ans_b * f << '\n';
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