#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), mx(n);
    for (auto & e : a) cin >> e;
    mx[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        mx[i] = max(mx[i- 1], a[i]);
    }
    ranges::reverse(mx);
    a.push_back(0);
    ranges::reverse(a);
    for (int i = 1; i < n; ++i)
    {
        a[i] += a[i - 1];
    }

    for (int i = 0; i < n; ++i)
    {
        // cout << mx[i] << ' ' ;
        cout << a[i] + mx[i]<< ' ';
    }
    cout << '\n';
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}