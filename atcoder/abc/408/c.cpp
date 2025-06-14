#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector <ll> d(n + 2);
    ll minn = m;

    while (m--)
    {
        int l, r;
        cin >> l >> r;
        d[l]++;
        d[r + 1] --;
    }
    for (int i = 1; i <= n; ++i)
    {
        d[i] += d[i - 1];
        // cout << d[i] << ' ';
        minn = min(minn, d[i]);
    }
    cout << max(minn, 0ll);
}