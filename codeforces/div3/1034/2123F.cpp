#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

vector<int> p;
vector<int> tf(100'000);
std::vector<bool> sieve(100'000 + 1, true); 

void solve()
{
    int n;
    cin >> n;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        ans[i] = i;
    }
    for (int i = 2; i <= n; ++i)
    {
        if (sieve[i] && i * 2 <= n) swap(ans[i], ans[i * 2]);
        else if (ans[i] == i && !sieve[i]) swap(ans[i], ans[tf[i]]);
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    cout << '\n'; 
}

std::vector<int> euler_sieve(int n) {
    std::vector<int> prime; 
    sieve[0] = sieve[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (sieve[i]) prime.push_back(i);
        for (auto &e : prime) {
            if (1LL * e * i > n) break;
            tf[e * i] = e;
            sieve[e * i] = false;
            if (i % e == 0) break;
        }
    }
    return prime;
}

int main()
{
    ios::sync_with_stdio(false);  
    cin.tie(nullptr), cout.tie(nullptr);  
    int t = 1;
    cin >> t;
    p = euler_sieve(100'000);
    // cout << p.size();
    while (t--)
    {
        solve();
    }
    return 0;
}