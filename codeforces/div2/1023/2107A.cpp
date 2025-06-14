#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto & e : a) cin >> e;
    bool f = 1;
    int maxn = a[0], index = 0;
    for (int i = 0 ; i < n; ++i)
    {
        if (a[i] > maxn) 
        {
            maxn = a[i];
            index = i;
        }
        if (a[i] != a[0]) f = false;
    }
    if (f) cout << "No\n";
    else 
    {
        cout << "Yes\n";
        for (int i = 0 ; i < n; ++i)
        {
            if (i != index) 
            {
                cout << 1 << ' ';
            }
            else cout << 2 << ' ';
           
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);  
    cin.tie(0), cout.tie(0);  

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}