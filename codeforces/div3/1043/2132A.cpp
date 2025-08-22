#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, m;
    string a, b, c;
    cin >> n >> a >> m >> b >> c;
    for (int i = 0; i < m; i++)
    {
        if (c[i] == 'V') a = b[i] + a;
        else a += b[i];
    }
    cout << a << '\n';
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