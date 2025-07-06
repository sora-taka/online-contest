#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int w, h, a, b;
    cin >> w >> h >> a >> b;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (min(x1, x2) + a <= max(x1, x2))
    {
        if ((min(y1, y2) + b) <= max(y1, y2))
        {
            if ((max(x1, x2) - (min(x1, x2) + a))% a == 0)
            {
                cout << "Yes\n";
            }
            else if ((max(y1, y2) - (min(y1, y2) + b)) % b == 0)
            {
                cout << "Yes\n";
            }
            else cout << "No\n";
        }
        else if ((max(x1, x2) - (min(x1, x2) + a) )% a == 0)
        {
            cout << "Yes\n";
        }
        else cout << "No\n";
    }
    else
    {
        if ((max(y1, y2) - (min(y1, y2) + b)) % b == 0)
        {
            cout << "Yes\n";
        } 
        else cout << "No\n";
    }
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