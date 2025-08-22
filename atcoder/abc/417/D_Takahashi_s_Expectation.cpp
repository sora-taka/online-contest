#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;

    using t3i = tuple<int, int, int>;

    vector<t3i> v(n);
    for (auto &[p, a, b] : v) cin >> p >> a >> b;

    t3i root{0, 1'000'000'000, 0};

    vector<pii> zero;
    
    queue<t3i> q;
    q.push(root);

    for (auto [p, a, b] : v)
    {
        int h = q.size();
        while (h--)
        {
            auto [l, r, dif] = q.front();
            q.pop();

            if (p < l + dif)
            {
                dif -= b;
                if (dif < 0)
                {
                    if (r <= -dif)
                    {
                        zero.push_back({l, r});
                    }
                    else
                    {
                        q.push({-dif + 1, r, dif});
                        zero.push_back({l, -dif});
                    }
                }
                else
                {
                    q.push({l, r, dif});
                }
            }
            else if (p >= l && p < r)
            {
                q.push({l, p, dif + a});
                l = p + 1;
                dif -= b;
                if (dif < 0)
                {
                    if (r <= -dif)
                    {
                        zero.push_back({l, r});
                    }
                    else
                    {
                        q.push({-dif + 1, r, dif});
                        zero.push_back({l, -dif});
                    }
                }
                else
                {
                    q.push({l, r, dif});
                }
            }
            else if (p >= r)
            {
                q.push({l, r, dif + a});
            }
        }
    }
    map<int, int> mp;
    while(q.size() > 0)
    {
        auto [l, r, dif] = q.front();
        q.pop();
        mp[l] = dif;
    }
    for (auto [l, r] : zero)
    {
        mp[l] = -1'000'000'000;
    }
    int QQ;
    cin >> QQ;
    while (QQ--)
    {   
        int x;
        cin>> x;
        auto p = mp.lower_bound(x);
        p--;
        cout << max(0, x + p->second) << '\n';
    }

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