#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), cnt(n + 2, 0);
    for (int & e : a) cin >> e, cnt[e]++;

    ll mex;
    for (int i = 0; i < cnt.size(); ++i)
    {
        if (cnt[i] == 0)
        {
            mex = i;
            break;
        }
    }
    ll bk;
    for (int i = 0; i < cnt.size(); ++i)
    {
        if (cnt[i] != 1) 
        {
            bk = i;
            break;
        }
    }

    if (bk == mex)
    {
        ll cnt = n - mex;
        ll sum = 0;
        if (mex != 0) sum = (0 + mex - 1) * mex / 2;
        if (k % 2 == 0 && cnt > 1) cout << sum + (mex + 1) * cnt << '\n';
        else cout << sum + mex * cnt << '\n';
    }
    else if (k == 1)
    {
        ll sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] < bk) sum += a[i];
            else if (a[i] < mex && cnt[a[i]] == 1) sum += a[i];
            else sum += mex;
        }
        cout << sum << '\n';
    }
    else
    {
        k -= 1;
        ll cnt = n - bk;
        ll sum = 0;
        if (bk != 0) sum = (0 + bk - 1) * bk / 2;
        if (k % 2 == 0 && cnt > 1) cout << sum + (bk + 1) * cnt << '\n';
        else cout << sum + bk * cnt << '\n';
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