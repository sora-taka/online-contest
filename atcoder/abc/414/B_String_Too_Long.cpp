#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    ll sum = 0;
    string s;
    while (n--)
    {
        char c;
        ll l;
        cin >> c >> l;
        sum += l;
        if (sum > 100) break;
        s += string(l, c);
    }
    if (sum <= 100) cout << s;
    else cout << "Too Long";
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