#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, l, r;
    string s;
    cin >> n >> l >> r >> s;
    bool f = true;
    for (int i = l - 1; i < r; ++i)
    {
        if (s[i] != 'o') f = false;
    }
    cout << (f ? "Yes":"No");
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