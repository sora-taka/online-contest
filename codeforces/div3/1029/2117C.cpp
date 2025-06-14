#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int & e : a) cin >> e;
    int cnt = 0;
    set<int> cur, seen;
    for (int e : a) 
    {
        cur.insert(e);
        seen.insert(e);
        if (cur.size() == seen.size())
        {
            cnt++;
            seen.clear();
        }
    }
    cout << cnt << '\n';
}

int main()
{
    ios::sync_with_stdio(0);  
    cin.tie(0), cout.tie(0);  
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}