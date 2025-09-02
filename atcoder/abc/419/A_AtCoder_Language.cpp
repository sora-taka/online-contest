#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    string s; cin >> s;
    if (s == "red") cout << "SSS";
    else if (s == "blue") cout << "FFF";
    else if (s == "green") cout << "MMM";
    else cout << "Unknown";
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