#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;


vector<bool> to(1000000 + 1);
vector<vector<int>> g(1000000+ 1);
void dfs( int r)
{
    to[r]= true;
    for (int e: g[r] )
    {
       if (!to[e]) dfs(  e);
    }
    
};



void solve()
{
    int n, m;
    cin >> n >> m;
    bool f = true;

    vector<int> vis(n + 1);

    
    while (m --)
    {
        int v, u;
        cin >> v >> u;
        vis[v]++;
        vis[u]++;
        g[v].push_back(u);
        g[u].push_back(v);
    }


    to[1] = true;
    dfs( 1);

    for (int i = 1; i <= n; ++i)
    {
        f = f && vis[i] == 2;
        f = f && to[i] ;
    }
    
    if (f) cout << "Yes";
    else cout << "No";
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