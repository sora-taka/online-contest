#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int & e : a) cin >> e;
    ranges::sort(a);
    int j = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            cout << a[j] << ' ';
            cout << a[m - j - 1] << ' ';
            cout << a[j] << ' ';
            cout << a[m - j - 1] << ' ';
            cout << a[j] << ' ';
            cout << a[m - j - 1] << ' ';
            cout << '\n';
        }
        else
        {
            cout << a[m - j - 1] << ' ';
            cout << a[j] << ' ';
            cout << a[m - j - 1] << ' ';
            cout << a[j] << ' ';
            cout << a[m - j - 1] << ' ';
            cout << a[j] << ' ';
            cout << '\n';
        }
        cnt += (a[m - j - 1] / 100 - a[j] / 100) * 5;
        if (i % 2 != 0) j++;
    }
    // cout << " ----- " << cnt << " --- \n";
    
}

int main()
{
    ios::sync_with_stdio(0);  
    cin.tie(0), cout.tie(0);  
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}