#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (s[0] == s[n - 1] && s[0] == 'A')
    {
        cout << "Alice\n";
        return;
    }

    if (s[n - 1] == s[n - 2] && s[n - 1] == 'A')
    {
        cout << "Alice\n";
        return;
    }
    int cnt  = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'A') cnt++;
    }
    if (s[n - 1] == 'B' && cnt == n - 1)
    {
        cout << "Alice\n";
        return;
    }
    cout << "Bob\n";
    return;
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