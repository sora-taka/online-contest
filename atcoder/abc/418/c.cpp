#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    sort(a.begin(), a.end());
    vector<long long> sum_a(n + 1);
    for (int i = 1; i <= n; i++) sum_a[i] = sum_a[i - 1] + a[i - 1];
    while (q--)
    {
        int b;
        cin >> b;
        int pos = lower_bound(a.begin(), a.end(), b) - a.begin();
        if (pos == n) cout << -1 << '\n';
        else cout << sum_a[pos] + 1ll * (b - 1) * (n - pos) + 1 << '\n';
    }
}