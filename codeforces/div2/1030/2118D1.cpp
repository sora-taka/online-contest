#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> p(n);
    for (auto & e : p) cin >> e;
    vector<int> d(n);
    for (auto & e : d) cin >> e;
    vector g(n, vector<vector<bool>>(k, {0, 0, 0})); 
    int q;
    cin >> q;
    bool f = true;
    while (q--)
    {
        ll x;
        cin >> x;
        int mv = 1, t = 0, idx = 0;
        while (true)
        {
            if (mv == 1)
            {
                for (int i = idx; i < n; ++i)
                {
                    if (p[i] == x)
                    {
                        if (d[i] == t)
                        {
                            x--;
                            
                        }
                        break;
                    }
                    else if (p[i] > x)
                    {

                        break;
                    }
                }
            }
            else
            {

            }

        }
        
        
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