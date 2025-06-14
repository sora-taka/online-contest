#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b + c) % 3 != 0)
    {
        cout << "NO\n";
        return;
    }

    int avg = (a + b + c) / 3;
    if (a <= avg && b<= avg ) cout << "YES\n";
    else cout << "NO\n";
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