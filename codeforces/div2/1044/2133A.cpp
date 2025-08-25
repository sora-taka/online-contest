#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    set<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.insert(x);
    }
    cout << (a.size() != n ? "YES" : "NO") << '\n';
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