#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int q; cin >> q;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (q--)
    {
        int op; cin >> op;
        if (op == 1)
        {   
            int x; cin >> x;
            pq.push(x);
        }
        else 
        {
            cout << pq.top() << '\n';
            pq.pop();
        }
    }
}

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