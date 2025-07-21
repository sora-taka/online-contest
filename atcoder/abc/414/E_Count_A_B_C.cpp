#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

long long binary_exp(long long base, long long exponent, long long mod) {
    long long result = 1;
    base %= mod;
    while (exponent > 0) {
        if (exponent & 1) result = (result * base) % mod; 
        exponent >>= 1;
        base = (base * base) % mod;
    }
    return result;
}

long long mod_inverse(long long number, long long prime_mod) {
    if (number % prime_mod == 0) return -1; 
    // By Fermat's Little Theorem: a^(p-2) ≡ a^(-1) (mod p)
    return binary_exp(number, prime_mod - 2, prime_mod);
}

ll mod = 998244353;

void solve()
{
    ll n;
    cin >> n;
    ll ans = (1 + n - 2) % mod * (n - 2) % mod * mod_inverse(2, mod) % mod;
    for (ll i = 2; i <= n / 2; ++i)
    {
        ans = (ans - (n / i - 1) % mod) % mod;
        // ans = (ans - (n / i / i - 1) % mod) % mod;
    }
    cout << ans;
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