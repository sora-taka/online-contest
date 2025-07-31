#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, x;
    cin >> n >> x;
    int cnt = 0;
    for (int i = 1; i < x - 1; ++i)
    {
        for (int j = i + 1; j < x; ++j) 
        {
            for (int k = j + 1; k <= x; ++k)
            {
                cout << i << ' ' << j << ' ' << k << '\n';
                cnt++;
            }
        }
    }
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