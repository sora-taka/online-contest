#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    int cnt = 0;
    for (auto c : s) if (c == '1') cnt++;
    if (n < k * 2 || cnt <= k) 
    {
        cout << "Alice\n";
    }
    else 
    {
        cout << "Bob\n";
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