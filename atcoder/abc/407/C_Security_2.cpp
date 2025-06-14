#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int cnt = s.size(), last = 0;
    for (auto e: s)
    {
        int num = e - '0';
        if (num == 0 && last != 0) num = 10; 
        if (num >= last) cnt += num - last, last = num;
        else cnt += num + 10 - last, last = num;
        if (last == 10) last = 0;
    }
    cout << cnt;
}

int main()
{
    ios::sync_with_stdio(0);  
    cin.tie(0), cout.tie(0);  

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}