#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;


std::vector<ll> euler_sieve(int n, std::vector<bool>* is_prime = nullptr) {
    std::vector<ll> prime;
    std::vector<bool> temp_is_prime;

    std::vector<bool>& sieve = is_prime ? *is_prime : temp_is_prime;
    
    sieve.assign(n + 1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (sieve[i]) prime.push_back(i);

        for (int e : prime) {
            if (1LL * e * i > n) break;

            sieve[e * i] = false;

            if (i % e == 0) break;
        }
    }
    return prime;
} 

vector<ll> p;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto & e : a) cin >> e;
    ranges::sort(a, greater<ll>());
    for (int i = 1; i < n; ++i)
    {
        a[i] += a[i - 1];
    }
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << a[i] << ' ';
    // }
    // cout << '\n';
    int len = n - 1;
    while (a[len] < p[len]) len--;
    cout << n - 1 - len << '\n';
}

int main() {
    p = euler_sieve(6'000'000);
    for (int i = 1; i < p.size(); ++i)
    {
        p[i] += p[i - 1];
    }

    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}