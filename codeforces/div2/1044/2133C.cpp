#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> reply(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cout << '?' << ' ' << i << ' ' << n << ' ';
        for (int j = 1; j <= n; j++) cout << j << ' ';
        cout << '\n';
        cout.flush();

        int x;
        cin >> x;
        reply[x].push_back(i);
    }
    int len;
    for (int i = 1; i <= n; i++)
    {
        if (reply[i].size() > 0) len = i;
    }

    int deep = len;
    int root = reply[deep].front();
    vector<int> res;
    res.push_back(root);

    while (deep)
    {
        deep--;
        root = res.back();
        for (int i = 0; i < reply[deep].size(); i++)
        {
            if (i == reply[deep].size() - 1)
            {
                res.push_back(reply[deep][i]);
                break;
            }

            cout << '?' << ' ' << root << ' ' << 2 << ' ' << root << ' ' << reply[deep][i] << ' ';
            cout << '\n';
            cout.flush();
            
            int c;
            cin >> c;
            if (c == 2)
            {
                res.push_back(reply[deep][i]);
                break;
            }
        }
    }

    cout << '!' << ' ' << len << ' ';
    for (auto i : res) cout << i << ' ';
    cout << '\n';
    cout.flush();   
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