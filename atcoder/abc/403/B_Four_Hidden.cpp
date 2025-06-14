#include <bits/stdc++.h>

#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

void solve()
{
    string t, u;
    cin >> t >> u;
    int I, J, K, H;
    I = t.find('?');
    J = t.find( '?', I + 1);
    K = t.find( '?', J + 1);
    H = t.find( '?', K + 1);
    // cout << I << ' ' << J << ' ' << K << ' ' << H ;
    bool f = false;
    for (char i = 'a'; i <= 'z'; ++i)
    {
        for (char j = 'a'; j <= 'z'; ++j)
        {
            for (char k = 'a'; k <= 'z'; ++k)
            {
                for (char h = 'a'; h <= 'z'; ++h)
                {
                    t[I] = i;
                    t[J] = j;
                    t[K] = k;
                    t[H] = h;
                    if (t.find(u) != string::npos) f |= true;
                }
            }
        }
    }
    if (f) cout << "Yes";
    else cout << "No";
}

int main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}