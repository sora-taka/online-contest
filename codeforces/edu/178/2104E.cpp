#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

void solve() {
    int n, k, q;
    string s;
    cin >> n >> k >> s >> q;
    vector<vector<int>> mp(256);
    for (int i = 0 ; i < s.size(); ++i)
    {
        mp[s[i]].push_back(i);
    }
    while (q--)
    {
        string t;
        cin >> t;
        if (k == 1)
        {
            if (t.size() <= s.size()) cout << s.size() - t.size() + 1;
            else cout << 0;
            cout << '\n';
            continue;
        }
        int l = -1;
        bool f = false;
        for (auto c : t)
        {
            auto & v = mp[c];
            auto iter = lower_bound(v.begin(), v.end(), l);
            if (iter == v.end())
            {
                f = true;
                break;
            }
            else l = v[iter - v.begin()] + 1;
        }
        if (f)
        {
            cout << 0 << '\n';
            continue;
        }
        int cnt = 0;

        while (true)
        {
            int maxn = l;
            for (char i = 'a'; i < 'a' + k; ++i)
            {
                auto & v = mp[i];
                auto iter = lower_bound(v.begin(), v.end(), l);
                if (iter == v.end())
                {
                    f = true;
                    break;
                }
                else maxn = max(maxn, v[iter - v.begin()] + 1);
            }
            cnt++;
            l = maxn;
            if (f) {
                cout << cnt << '\n';
                break;
            }
        }
        
        
        // cout << l << " : ";
        // cout << cnt << '\n';
    }
}

int main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}