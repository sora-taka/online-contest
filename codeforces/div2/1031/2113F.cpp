#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &e : a) cin >> e;
    for (auto &e : b) cin >> e;
    map<int, int> ma, mb;
    for (auto &e : a) ma[e]++;
    for (auto &e : b) mb[e]++;
    for (int i = 0; i < n; ++i)
    {
        if (ma[a[i]] > 1 && mb[b[i]] > 1 && (mb.find(a[i]) == mb.end() || ma.find(b[i]) == ma.end())) 
        {
            ma[a[i]]--;
            ma[b[i]]++;

            mb[b[i]]--;
            mb[a[i]]++;
            swap(a[i], b[i]);
        }
    }
    cout << ma.size() + mb.size() << '\n';
    for (auto &e : a) cout << e << ' ';
    cout << '\n';
    for (auto &e : b) cout << e << ' ';
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