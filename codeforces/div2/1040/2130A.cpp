#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int & e : a) cin >> e;
    ranges::sort(a);
    int sum = 0;
    for (int & e : a) sum += e;
    for (int & e : a) if (e == 0) sum++;
    cout << sum << '\n';
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