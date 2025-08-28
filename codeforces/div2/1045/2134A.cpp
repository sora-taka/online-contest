#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    if (b >= a)
    {
        cout << (b % 2 == n % 2 ? "YES" : "NO") << endl;
    }
    else
    {
        cout << (b % 2 == n % 2 && a % 2 == n % 2 ? "YES" : "NO") << endl;
    }
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