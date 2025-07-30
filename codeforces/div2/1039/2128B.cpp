#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto & e : p) cin >> e;
    bool f = true;
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (f)
        {
            if (p[l] > p[r]) cout << "LR"; else cout << "RL";
            // cout << (p[l] > p[r] ? to_string(p[l]) + ' ' + to_string(p[r]):  to_string(p[r]) + ' ' + to_string(p[l])) << ' ';
        }
        else
        {
            if (p[l] < p[r]) cout << "LR"; else cout << "RL";
            // cout << (p[l] < p[r] ? to_string(p[l]) + ' ' + to_string(p[r]):  to_string(p[r]) + ' ' + to_string(p[l])) << ' ';
        }
        l++, r--;
        f = !f;
    }
    if (l == r) cout << 'L';
    // if (l == r) cout << p[l];
    cout << '\n';
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