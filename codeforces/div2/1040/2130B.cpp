#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    int sum = 0;
    for (int &e : a) sum += e;
    if (sum > s) for (int &e : a) cout << e << ' ';
    else 
    {
        s -= sum;
        if (s == 1)
        {
            for (int &e : a) if (e == 0) cout << e << ' ';
            for (int &e : a) if (e == 2) cout << e << ' ';
            for (int &e : a) if (e == 1) cout << e << ' ';
        }
        else
        {
            cout << -1;
        }
        // else  for (int &e : a) cout << e << ' ';
    }
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