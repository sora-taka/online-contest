#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    string s;
    cin >> s;
    string t(s.size(), '.');
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '#') t[i] = '#';
    }
    bool f = true;
    for (int i = 0; i < t.size(); ++i)
    {
        if (t[i] == '.' && f) t[i] = 'o', f = false;
        if (t[i] == '#') f = true;
    }
    cout << t;
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