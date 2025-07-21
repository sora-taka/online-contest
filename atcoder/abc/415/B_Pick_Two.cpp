#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    string s;
    cin >>s ;
    vector<int> v;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '#') v.push_back(i + 1);
    }
    for (int i = 0; i < v.size(); i += 2)
    {
        cout << v[i] << ',' << v[i + 1] << '\n';
    }
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