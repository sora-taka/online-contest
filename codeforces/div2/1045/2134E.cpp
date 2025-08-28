#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> ans(n + 1, -1);
    vector<int> idx(n + 1);
    for (int i = 1; i <= n; i++) idx[i] = i;

    cout << "throw " << n - 1 << '\n';
    cout.flush();

    int reply;
    cin >> reply;
    if (reply == 1) ans[n - 1] = 2;
    else ans[n - 1] = 1;

    cout << "swap " << n - 1 << '\n';
    swap(idx[n - 1], idx[n]);
    cout << "throw " << n - 1 << '\n';
    cout.flush();

    cin >> reply;
    if (reply == 1) ans[n] = 2;
    else ans[n] = 1;

    
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
    cout.flush();
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