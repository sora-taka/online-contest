#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto & e : s) cin >> e;
    vector<int> a(n);
    for (int j = 0; j < m; j++)
    {
        vector<int> one, zero;
        for (int i = 0; i < n; i++)
        {
            if (s[i][j] == '1') one.push_back(i);
            else zero.push_back(i);
        }
        if (one.size() < zero.size())
        {
            for (auto e : one) a[e]++;
        } 
        else
        {
            for (auto e : zero) a[e]++;
        }
    }
    int maxn = *ranges::max_element(a);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == maxn) cout << i + 1 << ' ';
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