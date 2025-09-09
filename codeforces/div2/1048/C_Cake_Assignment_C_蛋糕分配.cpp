#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    ll k, x;
    cin >> k >> x;
    ll tot = 1ll << (k + 1);

    int n = [](ll a, ll b){
        int cnt = 0;
        while (a != b) a <<= 1, cnt++;
        return cnt;
    }(x & -x, tot / 2);

    ll up = x / (tot / (1ll << (n + 1)));
    ll down = 1ll << (n + 1); 

    // cout << up << ' ' << down << '\n';
    cout << n << '\n';

    vector<int> ans;
    int op = 1, nop = 2;
    for (int i = 0; i < n; i++)
    {
        down >>= 1;
        if (up > down) 
        {
            ans.push_back(nop);
            up = down * 2 - up;
            swap(op, nop);
        }
        else ans.push_back(op);
    }
    ranges::reverse(ans);
    for (auto e : ans) cout << e << " ";
    cout << '\n';
    // cout << tot << endl;
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