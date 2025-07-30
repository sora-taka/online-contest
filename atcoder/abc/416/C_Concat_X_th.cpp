#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    if (n > 10) abort();
    vector<string> s(n);
    for (auto &e : s) cin >> e;

    ranges::sort(s);

    vector<string> ans;

    auto dfs = [&](auto &self, int l, string path)
    {
        if (l == k)
        {
            ans.push_back(path);
            return;
        }
        for (string e : s)
        {
            self(self, l + 1, path + e);
        }
    };
    dfs(dfs, 0, "");
    // for (string e : ans) cout << e << ' ';
    ranges::sort(ans);
    x--;
    cout << ans[x];
    // vector<int> res;
    // while (k--)
    // {
    //     res.push_back(ans[x] % 10);
    //     ans[x] /= 10;
    // }
    // ranges::reverse(res);
    // for (int e : res) cout << s[e];
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