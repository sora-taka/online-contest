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
    int n;
    cin >> n;
    int x = 0;
    ll ans = 0;
    while (n)
    {
        ans += n % 3 * (binary_exp(3, x + 1) + x * binary_exp(3, x - 1));
        n /= 3;
        x++;
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