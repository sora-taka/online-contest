#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector f(m, vector(m, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = i; j < n; j += m)
        {
            
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