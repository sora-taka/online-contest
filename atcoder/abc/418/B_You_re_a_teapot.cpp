#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 2; j < n; j++)
        {
            int cnt = 0;
            for (int k = i; k <= j; k++)
            {
                cnt += s[k] == 't';
            }
            if (s[i] == 't' && s[j] == 't') ans = max(ans, (cnt - 2.0) / (j - i - 1.0));
        }
    }
    cout << fixed << setprecision(10) << ans;
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