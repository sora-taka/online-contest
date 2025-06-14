#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    char k = '#';
    queue<char> q1, q2;
    for (auto c : s) q2.push(c);
    while (!q2.empty())
    {
        char c = q2.front();
        q2.pop();
        if (q2.empty() || c <= q2.front()) q1.push(c);
        else
        {
            k = c;
            break;
        }
    }
    while (!q2.empty() && k >= q2.front())
    {
        q1.push(q2.front());
        q2.pop();
    }
    while (!q1.empty())
    {
        cout << q1.front();
        q1.pop();
    }
    if (k != '#') cout << k;
    while (!q2.empty())
    {
        cout << q2.front();
        q2.pop();
    }
    cout << '\n';
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