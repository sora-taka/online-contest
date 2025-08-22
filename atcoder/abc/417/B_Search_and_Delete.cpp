#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, m;
    cin >> n >> m;
    map<int, int> a;
    vector<int> b(m);
    for (int i = 0; i < n; ++i) 
    {
        int x;
        cin >> x;
        a[x] ++;
    }
    for (int & e : b) 
    {
        cin >> e;
        if (a[e] > 0) a[e] --;
    }
    for (auto &[k, v] : a)
    {
        while (v > 0)
        {
            cout << k << ' ';
            v--;
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