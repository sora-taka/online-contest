#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, l;
    cin >> n >> l;
    vector<int> a(l);
    int pos = 0;
    a[0] = 1;
    for (int i = 0; i < n - 1; ++i)
    {
        int d;
        cin >> d;
        pos = (pos + d) % l;
        a[pos] ++;
    }
    if (l % 3 != 0)
    {
        cout << 0;
        return;
    }
    // for (auto e: a)
    // {
    //     cout << e << ' ';
    // }
    
    ll cnt = 0;
    for (int i = 0; i < l; ++i)
    {
        if (i + l / 3 * 2 >= l) break;
        if (a[i] && a[(i + l / 3) % l] && a[(i + l / 3 * 2) % l])
        {
            cnt += 1ll * a[i] * a[(i + l / 3) % l] * a[(i + l / 3 * 2) % l];
            // a[i] = a[(i + l / 3) % l]= a[(i + l / 3 * 2) % l] = false;
        }
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