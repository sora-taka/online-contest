#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

// ba, bc, bca, ca, cb, cba
int cz[10];
void solve()
{
    int n, q;
    string s;
    cin >> n >> q >> s;
    for (int i = 0; i < q; ++i) 
    {
        char x, y;
        cin >> x >> y;
        if (x == 'b' && y == 'a') cz[0]++;
        if (x == 'b' && y == 'c') cz[1]++;

        if (x == 'c' && y == 'a' && cz[1] > cz[2]) cz[2]++;
        if (x == 'c' && y == 'a') cz[3]++;

        if (x == 'c' && y == 'b') cz[4]++;
        if (x == 'c' && y == 'b'&& cz[0] > cz[5]) cz[5]++;
    }
    for( char & c : s)
    {
        if (c == 'b')
        {
            if (cz[0] > 0) 
            {
                cz[0]--;
                c = 'a';
            }
            else if (cz[2] > 0 && cz[1] > 0 && cz[3] > 0)
            {
                cz[2]--;
                cz[1]--;
                cz[3]--;
                c = 'a';
            }

        }
        else if (c == 'c')
        {
            if (cz[3] > 0)
            {
                cz[3]--;
                c = 'a';
            }
            else if (cz[5] > 0 && cz[4] > 0&& cz[0] > 0)
            {
                cz[5]--;
                cz[4]--;
                cz[0]--;
                c = 'a';
            }
            else if (cz[4] > 0)
            {
                cz[4]--;
                c = 'b';
            }
        }
    }
    cout << s << '\n';
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

