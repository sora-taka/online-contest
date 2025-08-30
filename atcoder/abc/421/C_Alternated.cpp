#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    vector <int> a;
    for (int i = 0; i < n * 2; ++i)
    {
        if (s[i] == 'A') a.push_back(i);
    }

    ll cost1 = 0, cost2 = 0;
    for (int i = 0; i < n; ++i)
    {
        cost1 += abs(i * 2 - a[i]);
        cost2 += abs(i * 2 + 1 - a[i]);
    }
   

    cout << min(cost1, cost2);
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