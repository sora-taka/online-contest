#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<vector<bool>> g(n, vector<bool>(n)), s(n, vector<bool>(n)), t(n, vector<bool>(n));
    for (int i = 0 ; i < n; ++i)
    {
        for (int j = 0 ; j < n; ++j)
        {
            char c; cin >> c;
            if (c == '#') s[i][j] = true;
        }
    }
    // for (int i = 0 ; i < n; ++i)
    // {
    //     for (int j = 0 ; j < n; ++j)
    //     {
            
    //         cout << s[i][j] << " \n"[j == n - 1];
    //     }
    // }
    for (int i = 0 ; i < n; ++i)
    {
        for (int j = 0 ; j < n; ++j)
        {
            char c; cin >> c;
            if (c == '#') t[i][j] = true;
        }
    }
    // for (int i = 0 ; i < n; ++i)
    // {
    //     for (int j = 0 ; j < n; ++j)
    //     {
            
    //         cout << t[i][j] << " \n"[j == n - 1];
    //     }
    // }
    int minn = 1e9;
    int v[] = {0, 3, 2, 1};
    for (int q = 0 ; q < 4; ++q)
    {
        int cnt = v[q];
        for (int i = 0 ; i < n; ++i)
        {
            for (int j = 0 ; j < n; ++j)
            {
                
                if (t[i][j] != s[i][j]){ cnt++;
                // cout << i << ' ' << j << '\n';
                }
            }
        }
            // for (int i = 0 ; i < n; ++i)
            // {
            //     for (int j = 0 ; j < n; ++j)
            //     {
                    
            //         cout << s[i][j] << " \n"[j == n - 1];
            //     }
            // }
        for (int i = 0 ; i < n; ++i)
        {
            for (int j = 0 ; j < n; ++j)
            {
                g[i][j] = s[j][n - i - 1];
            }
        }

        for (int i = 0 ; i < n; ++i)
        {
            for (int j = 0 ; j < n; ++j)
            {
                s[i][j] = g[i][j] ;
            }
        }
        minn = min(minn, cnt);
    }
    cout << minn;
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