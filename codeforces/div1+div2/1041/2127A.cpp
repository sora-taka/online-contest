#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int maxn = *ranges::max_element(a);
    bool f = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1) continue;
        f &= a[i] == maxn;
    }
    cout << (f && maxn != 0 ? "YES" : "NO") << '\n';
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