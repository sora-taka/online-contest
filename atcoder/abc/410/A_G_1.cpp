#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector <int> v(n);
    for (auto & e : v) cin >> e;
    int k;
    cin >> k;
    int cnt = 0;
    for (auto & e : v) cnt += (k <= e);
    cout << cnt;
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