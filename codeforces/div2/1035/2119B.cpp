#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    long double px, py, qx, qy;
    cin >> px >> py >> qx >> qy;
    long double len = sqrt((px - qx) * (px - qx) + (py - qy) * (py - qy));
    vector<long double> a(n);
    for (auto &e : a) cin >> e;
    bool f = true;
    if (n == 1) f = a[0] == len;
    else 
    {
        a.push_back(len);
        ranges::sort(a);
        long double sum = 0;
        for (auto e: a) sum += e;
        f = sum - a[n] >= a[n];
    }
    cout << (f ? "Yes" : "No") << '\n';
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