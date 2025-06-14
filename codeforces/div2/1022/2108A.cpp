#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

vector<int> ans(501);
void solve()
{
    int n;
    cin >> n;
    cout << ans[n]<< '\n';
}

int main()
{
    // Fast I/O optimization
    ios::sync_with_stdio(0);  // Disable synchronization with C stdio
    cin.tie(0), cout.tie(0);  // Untie cin and cout for faster I/O



    ans[1] = 1;
    for (int i = 2; i <= 500; i+= 2)
    {
        ans[i] = ans[i - 1] + i / 2;
        ans[i + 1] = ans[i] + i / 2 ;    
    }
    
    int t = 1;
    cin >> t;   
    while (t--)
    {
        solve();
    }
    return 0;
}