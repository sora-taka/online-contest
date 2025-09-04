#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, k;
    cin >> n >> k;
    map<int, int> a, b;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        a[x % k]++;
    }
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        b[x % k]++;
    }
    bool f = true;
    for (auto [k, v] : a){
        if (b[k] != v) f = false;
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