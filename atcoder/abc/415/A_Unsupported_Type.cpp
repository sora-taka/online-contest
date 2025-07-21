#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    set<int> st;
    while (n--)
    {
        int a;
         cin >> a;
         st.insert(a);
    }
    int x;
    cin >> x;
    cout << (st.find(x) != st.end()?"Yes":"No");
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