#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{    
    int m;
    cin >> m;
    vector<int> a(m), b;
    for (int & e : a) cin >> e;
    b.push_back(a[0]);
    for (int i = 1; i < m; ++i)
    {
        if (a[i] != b.back()) b.push_back(a[i]);
    }
    int n = b.size();
    ranges::reverse(b);
    int base = 1;
    double l = 1, r = 1e9;
    for (int i = 1; i < n; ++i)
    {
        if (b[i - 1] % b[i] != 0)
        {
            int t = gcd(b[i - 1], b[i]);
            l = max(l, b[i] / t * 1.0);
            if (base == 1) base = b[i];
            else base = gcd(base, b[i]);
        }
    }
    cout << base << ' ' << l << ' ' << r ;
    cout << " Ans : ";
    for (int i = 1; i < n; ++i)
    {
        if (b[i] > b[i - 1])
        {
            if (base == 1)
            {
                base = b[i];
                l = 1.0 * b[i] / b[i - 1];
                if (i + 1 < n) r = 1.0 * b[i] / b[i + 1];
            }
            else
            {
                base = gcd(base, b[i]);
                l = max(l, 1.0 * b[i] / b[i - 1]);
                if (i + 1 < n) r = min(r, 1.0 * b[i] / b[i + 1]);
            }
        }
        
    }

    for (int i = 1; i * i <= base; ++i)
    {
        if (base % i == 0)
        {
            if (i >= l && i <= r)
            {
                cout << i << '\n';
                break;
            }
            else if (base / i >= l && base / i <= r)
            {
                cout << base / i << '\n';
                break;
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
