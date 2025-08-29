#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> sa(n + 1);
    for (int i = 0; i < n; i++)
    {
        sa[i + 1] = sa[i] + s[i] - '0';
    }
    bool f = true;
    // cout << s << '\n';
    for (int l = 1; l + k - 1 <= n; l++)
    {
        // cout << l - 1 << ' ' << l + k - 1 << '\n';
        // cout << sa[l - 1] << ' ' << sa[l + k - 1] << '\n';
        if (sa[l + k - 1] - sa[l - 1] == k) f = false;
    }
    if (f) cout << "YES\n";
    else 
    {
        cout << "NO\n";
        return;
    }

    int cnt = n;

    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == '0') ans[i] = cnt --;
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == '1') ans[i] = cnt --;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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