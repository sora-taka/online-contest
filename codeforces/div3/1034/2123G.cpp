#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(n);
    for (int & e : a) cin >> e;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int i, x;
            cin >> i >> x;
            a[i - 1] = x;
        }
        else
        {
            int k;
            cin >> k;
            k = gcd(k, m);
            b[0] = a[0] % k;
            bool f = true;
            for (int i = 1; i < n; ++i)
            {
                b[i] = a[i] % k;
                if (b[i] >= b[i - 1]) continue;
                if (b[i] % k >= b[i - 1] % k)
                    b[i] = b[i - 1] - b[i - 1] % k + b[i] % k;
                else 
                    b[i] = b[i - 1] - b[i - 1] % k + b[i] % k + k;
                if (b[i] >= m) {
                    f = false;
                    cout << "NO\n";
                    break;
                }
            }
            // cout << k << ' ';
            //     for (int i = 0; i < n; ++i)
            //     {
            //         // cout << a[i] << '-';    
            //         cout << b[i] << ' ';
            //     }
            //     cout << '\n';
            if (f) cout << "YES" << '\n';
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