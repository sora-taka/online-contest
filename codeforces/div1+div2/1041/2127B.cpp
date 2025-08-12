#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, x;
    string s;
    cin >> n >> x >> s;
    int l = 0, l_idx = -1, r_idx = n, r = 0;
    for (int i = 0; i < x - 1; i++) 
    {
        if (s[i] == '#')
        {
            l++;
            l_idx = i;
        }
    }
    for (int i = n - 1; i >= x - 1; i--)
    {
        if (s[i] == '#')
        {
            r++;
            r_idx = i;
        }
    }
    if (l + r == 0 || x == 1 || x == n) cout << 1 << '\n';
    else cout << max(min(l_idx + 1, n - x), min(x - 1, n - r_idx)) + 1 << '\n';
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