#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(n), idx(n);
    for (int & e : a) cin >> e;
    for (int & e : b) cin >> e;
    for (int i = 0; i < n; ++i) idx[i] = i;
    ranges::sort(idx, [](int x, int y)
    {
        return a[x] +    
    });
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