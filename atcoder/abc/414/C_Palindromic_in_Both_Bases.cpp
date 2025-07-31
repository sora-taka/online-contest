#include <bits/stdc++.h>
#include <ranges>
using namespace std;

using ll = long long;
using pii = pair<int, int>;


bool is_a_pal(ll x , ll a)
{
    string s;
    while(x) s += char(x % a + '0'), x /= a;
    string t(s.size(), ' ');
    ranges::reverse_copy(s, t.begin());
    return s == t;
}

void solve()
{
    ll a, n;
    cin >> a >> n;
    ll sum = 0;
    for (ll i = 0; i <= 999999; ++i)
    {
        // 奇数长度
        for (ll j = 0; j <= 9; ++j)
        {
            ll t = i, x = i * 10 + j;
            while (t) 
            {
                x = x * 10 + t % 10;
                t = t / 10;
            }
            if (x <= n && is_a_pal(x, a)) sum += x;
        }
        // 偶数长度
        ll t = i, x = i;
        while (t) 
        {
            x = x * 10 + t % 10;
            t = t / 10;
        }
        if (x <= n && is_a_pal(x, a)) sum += x;
    }
    cout << sum << '\n';
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