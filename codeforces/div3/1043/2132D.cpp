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

vector<ll> a;

void solve()
{
    ll k;
    cin >> k;
    ll number, next_len;
    for (ll i = 1; i < a.size(); i++)
    {
        if (k <= a[i])
        {
            number = (k - a[i - 1]) / i;
            if (i != 1) number += binary_exp(10, i - 1) - 1;
            next_len = (k - a[i - 1]) % i;
            break;
        }
    }

    // cout << number << ' ' << next_len << ' ';
    // ll len = 0;
    // for (ll i = 1; i <= number; ++i)
    // {
    //     len += to_string(i).size();
    // }
    // cout << len << '\n';

    ll ans = 0;
    for (ll i = 1; i <= 9; ++i)
    {
        ll t = 10;
        while (true)
        {
            ll ori = ans;
            ans += number / t * (t / 10) * i;
            ans += max(min(number % t - (i * (t / 10) - 1), t / 10), 0ll) * i;
            if (ans == ori) break;
            t *= 10;
        }
    }
    if (next_len != 0)
    {
        string s = to_string(number + 1);
        for (int i = 0 ; i < next_len; i++)
        {
            ans += s[i] - '0';
        }
    }
    
    cout << ans << '\n';
}

int main()
{
    ll mk = 1'000'000'000'000'000;
    a.push_back(0);
    ll m = 9;
    a.push_back(m);
    for (int i = 1; a[i] < mk; i++)
    {
        m *= 10;
        a.push_back(a[i] + m * (i + 1));
    }

    // for (auto x : a) cout << x << '\n';

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