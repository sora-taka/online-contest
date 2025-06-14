#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a, b;
    
    for (int i = 1; i <= n; i += 2) a.push_back(i);
    for (int i = 2; i <= n; i += 2) b.push_back(i);
    ranges::reverse(b);
    for (auto e : a) cout << e << ' ';
    for (auto e : b) cout << e << ' ';
    cout << '\n';
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