#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int & e : a) cin >> e;
    vector<bool> p(n), s(n);
    p[0] = p[n - 1] = true;
    int minn = a[0];
    for (int i = 1; i < n; ++i)
    {
        if (a[i] <= minn) 
        {
            p[i] = true;
            minn = a[i];
        }
    }
    int maxn = a[n - 1];
    for (int i = n - 1; i >= 1; --i)
    {
        if (a[i] >= maxn) 
        {
            s[i] = true;
            maxn = a[i];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << (p[i] || s[i]);
    }
    cout << '\n';
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