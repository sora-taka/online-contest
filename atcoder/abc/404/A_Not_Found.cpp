#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    string s;
    cin >> s;
    set<char> st;
    for (auto e:s ) st.insert(e);
    for (char c  = 'a'; c <= 'z'; ++c) 
    {
        if (st.find(c) == st.end())
        {
            cout << c;
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);  
    cin.tie(0), cout.tie(0);  

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}