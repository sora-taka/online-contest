#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int zero = count_if(s.begin(), s.end(), [](char c){ return c == '0'; });
    int cnt = count_if(s.begin(), s.begin() + zero, [](char c){ return c == '1'; });
    cout << cnt << '\n';
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