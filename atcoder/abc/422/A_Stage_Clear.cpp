#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    string s;
    cin >> s;
    int i = stoi(s.substr(0, s.rfind('-')));
    int j = stoi(s.substr(s.find('-') + 1));
    if (j < 8) cout << i << '-' << j + 1 << endl;
    else if (i < 8 && j == 8) cout << i + 1 << '-' << 1 << endl;
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