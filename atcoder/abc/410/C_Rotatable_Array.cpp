#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = i + 1;
    int base = 0;
    while (q--)
    {
        int op, p, x, k;
        cin >> op;
        if (op == 1) 
        {
            cin >> p >> x;
            p--;
            a[(base + p) % n] = x;
        }
        else if (op == 2)
        {
            cin >> p;
            p--;
            cout << a[(base + p) % n] << '\n';
        }
        else 
        {
            cin >> k;
            base = (base + k) % n;
        }
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