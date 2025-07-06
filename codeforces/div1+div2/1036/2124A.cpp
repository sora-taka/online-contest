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
    bool f = false;
    int x, y;
    for (int i = 1; i < n; ++i)
    {
        if (a[i - 1] > a[i])
        {
            f = true;
            x = a[i - 1];
            y = a[i];
            break;
        }
    }
    if (f)
    {
        cout << "YES\n2\n" << x << " " << y << '\n';
    }
    else cout << "NO\n";
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