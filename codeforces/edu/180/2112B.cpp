#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e : a) cin >> e;
    ll d = a[1] - a[0];
    bool f = true;
    for (int i = 1; i < n; ++i)
    {
        if (abs(a[i] - a[i - 1]) <= 1) 
        {
            cout << 0 << '\n'; 
            return;
        }
        if ((a[i] - a[i - 1]) * d < 0) f = false;
    }
    cout << (f ? -1 : 1) << '\n';
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