#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, k;
    cin >> n >> k;
    ll u = 0;
    vector<int> b;

    if (k % 2 == 0) 
    {
        b.push_back(k / 2);
        b.push_back(k / 2);
    }
    else 
    {
        b.push_back(k / 2);
        b.push_back(k / 2 + 1);
        u = 1;
    }
    n--;

    while (n)
    {
        vector<int> tmp;
        for (auto e : b)
        {
            if (e % 2 == 0)
            {
                tmp.push_back(e / 2);
                tmp.push_back(e / 2);
            }
            else
            {
                tmp.push_back(e / 2);
                tmp.push_back(e / 2 + 1);
            }
        }
        b = tmp;
        n--;
    } 
    cout << *ranges::max_element(b) - *ranges::min_element(b) << '\n';
    for (auto e : b) cout << e << ' ';
    cout << '\n';
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