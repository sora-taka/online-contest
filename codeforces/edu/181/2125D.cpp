#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

long long binary_exp(long long base, long long exponent, long long mod)
{
    long long result = 1;
    base %= mod;
    while (exponent > 0)
    {
        if (exponent & 1)
            result = (result * base) % mod;
        exponent >>= 1;
        base = (base * base) % mod;
    }
    return result;
}

long long mod_inverse(long long number, long long prime_mod)
{
    if (number % prime_mod == 0)
        return -1;
    // By Fermat's Little Theorem: a^(p-2) ≡ a^(-1) (mod p)
    return binary_exp(number, prime_mod - 2, prime_mod);
}

long long mod_div(long long a, long long b, long long mod)
{
    a %= mod;
    long long b_inv = mod_inverse(b, mod);
    if (b_inv == -1)
        return -1;
    return (a * b_inv) % mod;
}

ll MOD = 998244353;

void solve()
{
    int n, m;
    cin >> n >> m;
    using t3l = tuple<ll, ll, ll>;
    vector<vector<t3l>> g(m + 1);
    ll base = 1;
    for (int i = 0; i < n; ++i)
    {
        ll l, r, p, q;
        cin >> l >> r >> p >> q;
        base = base * mod_div(q - p, q, MOD) % MOD;
        g[l].push_back({r + 1, p, q});
    }
    vector<ll> dp(m + 2, 0);
    for (auto [r, p, q] : g[1])
    {
        dp[r] = (dp[r] + base * mod_div(q, q - p, MOD) % MOD * mod_div(p, q, MOD) % MOD) % MOD;
    }
    
    for (int i = 2; i <= m; ++i)
    {
        if (dp[i] != 0)
        {
            for (auto [r, p, q] : g[i])
            {
                dp[r] = (dp[r] + dp[i] * mod_div(q, q - p, MOD) % MOD * mod_div(p, q, MOD) % MOD) % MOD;
            }
        }
    }
    cout << dp[m + 1] << '\n';
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