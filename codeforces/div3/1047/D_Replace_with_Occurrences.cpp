#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> b(n);
    for (int & e : b) cin >> e;
    map<int, int> mp;
    for (int e : b) mp[e]++;
    int cnt = 0;
    bool flag = true;
    for (auto [k, v] : mp) 
    {
        if (v % k == 0) cnt += v;
        else flag = false;
    }
    if (!flag || cnt != n)
    {
        cout << -1 << '\n';
        return;
    }
    int a = 1;
    map<int, int> mp2, mp3;
    for (int i = 0; i < n; i++)
    {
        if (mp2[b[i]] == 0) 
        {
            mp2[b[i]] = a; 
            a++;
        }
        cout << mp2[b[i]] << ' ';
        mp3[b[i]] ++;
        if (mp3[b[i]] == b[i])
        {
            mp3[b[i]] = 0;
            mp2[b[i]] = a;
            a++;
        }
    }
    cout << '\n';

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