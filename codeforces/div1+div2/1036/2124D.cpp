#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b;
    for (int & e : a) cin >> e;
    if (k == 1)
    {
        cout << "YES\n";
        return;
    }
    vector t = a;
    ranges::sort(t);
    for (int e : a) if (e <= t[k - 2]) b.push_back(e);
    // for (int e : b) cout << e << ' '; cout << '\n';
    int l = 0, r = b.size() - 1, len = b.size();
    while (l < r)
    {
        if (b[l] == b[r]) l++, r--;
        else if (b[l] == t[k - 2]) l++, len--;
        else if (b[r] == t[k - 2]) r--, len--;
        else l = r, len = 0;
    }
    cout << (len >= k - 1 ? "YES" : "NO") << '\n'; 
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