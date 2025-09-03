#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<int> d(n + 1);
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        d[l - 1]++;
        d[r]--;
    }
    for (int i = 1; i < n; i++) d[i] += d[i - 1];
    for (int i = 0; i < n; i++) if (d[i] % 2 != 0) swap(s[i], t[i]); 
    cout << s << '\n';
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