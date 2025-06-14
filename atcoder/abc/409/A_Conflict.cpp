#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    string s, t;
    cin >> n >> s >> t;
    bool f = 0;
    for (int i= 0; i < n; ++i) if (s[i] == t[i] && s[i] == 'o') f = 1;
    if (f) cout << "Yes";
    else cout << "No";
}

int main()
{
    ios::sync_with_stdio(0);  
    cin.tie(0), cout.tie(0);  
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}