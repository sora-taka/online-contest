#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

// 覆盖一般，考虑中心点
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(2'000'010);
    while (n--)
    {
        int l, r;
        cin >> l >> r;
        a[l + r] ++;
    }
    partial_sum(a.begin(), a.end(), a.begin());
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << a[r * 2] - a[l * 2 - 1] << '\n';
    }
    
}
/*

1 1.5 2 2.5 3 3.5 4 4.5 5
2 3   4 5   6  7  8  9  10

*/
int main()
{
    ios::sync_with_stdio(false);  
    cin.tie(nullptr), cout.tie(nullptr);  
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}