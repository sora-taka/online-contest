#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a;
    a.push_back(0);
    for (int i = 1; i <= n; ++i) 
    {
        int x;
        cin >> x;
        if (x != a.back()) a.push_back(x);
    }
    a.push_back(0);
    int cnt = 0;
    for (int i = 1; i < a.size() - 1; ++i)
    {
        if (a[i - 1] < a[i] && a[i] > a[i + 1]) cnt++;
    }
    cout <<cnt <<'\n';
}

int main()
{
    ios::sync_with_stdio(0);  
    cin.tie(0), cout.tie(0);  

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}