#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

long long binary_exp(long long base, long long exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent & 1) result = (result * base); 
        exponent >>= 1;
        base = (base * base);
    }
    return result;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a;
    ll cnt = 0;
    while (n)
    {
        a.push_back(n % 3);
        cnt += n % 3;
        n /= 3;
    }

    if (cnt > k)
    {
        cout << -1 << '\n';
        return;
    }

    for (int i = a.size() - 1; i > 0 && cnt + 2 <= k; i--)
    {
        ll t = (k - cnt) / 2;
        if (a[i] != 0)
        {
            a[i - 1] += 3 * min(t, a[i]);
            cnt += 2 * min(t, a[i]);
            a[i] -= min(t, a[i]);
        }
        while (a[i] != 0 && cnt + 2 <= k)
        {
            a[i - 1] += 3;
            cnt += 2;
            a[i]--;
        }
    }

    ll ans = 0;

    for (int i = 0; i < a.size(); i++)
    {
        ans += a[i] * (binary_exp(3, i + 1) + i * binary_exp(3, i - 1));
    }

    cout << ans << '\n';
    
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