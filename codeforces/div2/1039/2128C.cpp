#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> b(n);
    for (int &e : b) cin >> e;
    bool f = true;
    int minn = b[0];
    for (int i = 1; i < n; ++i)
    {
        f &= (b[i] / 2 + 1 <= minn);
        // cout << f << ' ';
        minn = min(minn, b[i]);
    }
    cout << (f ? "YES" : "NO") << '\n';
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