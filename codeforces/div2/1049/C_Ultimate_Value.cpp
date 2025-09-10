#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> ori(n);
    for (int & e : ori) cin >> e;
    ll sum = 0;
    for (int i = 0; i < n; i++) 
    {
        if (i % 2 == 0) sum += ori[i];
        else sum -= ori[i];
    }
    // cout << sum << ' ';

    ll dif0 = 0, dif1 = 0, dif2 = 0;
    if (n > 1)
    {
        if (n % 2 == 0) dif0 = n - 2;
        else dif0 = n - 1;
        // cout << dif0 << ' ';
        vector<int> a, b;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0) a.push_back(2 * -ori[i] - i - 1);
            else b.push_back(2 * ori[i] + i + 1);
        }
        dif1 = *ranges::max_element(a) + *ranges::max_element(b);
        // cout << dif1 << ' ';
        vector<int> c, d;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 1) c.push_back(2 * ori[i] - i - 1);
            else d.push_back(2 * -ori[i] + i + 1);
        }
        dif2 = *ranges::max_element(c) + *ranges::max_element(d);
        // cout << dif2 << '\n';
    }
    
    cout << sum + max({dif0, dif1, dif2}) << '\n';
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