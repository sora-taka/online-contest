#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<bool> vis(n + 1);
    vector<set<int>> vst(n + 1);
    while (q--)
    {
        char c;
        cin >> c;
        if (c == '1')
        {
            int x, y;
            cin >> x >> y;
            vst[x].insert(y);
        }
        else if (c == '2')
        {
            int x;
            cin >> x;
            vis[x] = true;
        }
        else 
        {
            int x, y;
            cin >> x >> y;
            if (vis[x] || vst[x].count(y) != 0) cout << "Yes\n";
            else cout << "No\n";
        }
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