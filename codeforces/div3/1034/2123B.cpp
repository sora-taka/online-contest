#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, j, k;
    cin >> n >> j >> k;
    vector<int> a(n);
    for (auto & e : a) cin >> e;
    if (k == 1 && a[j - 1] < *ranges::max_element(a))
    {
        cout << "NO\n";
        return ;
    }
    cout << "YES\n";
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