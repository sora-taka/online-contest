#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    string s, a, b;
    cin >> s;
    for (char c : s) 
    {
        if (c == 'F') b += c;
        else if (c == 'N') b += c;
        else a += c;
    }
    cout << a + b << '\n';
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