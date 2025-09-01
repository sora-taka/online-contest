#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve()
{
    ll r_t, c_t, r_a, c_a;
    cin >> r_t >> c_t >> r_a >> c_a;
    ll n, m, l;
    cin >> n >> m >> l;
    queue<pair<char, int>> q_t, q_a;
    while (m--)
    {
        char s;
        int a;
        cin >> s >> a;
        q_t.emplace(s, a);
    }
    while (l--)
    {
        char t;
        int b;
        cin >> t >> b;
        q_a.emplace(t, b);
    }
    vector<char> d_t, d_a;
    vector<int> move_len;
    while (!q_a.empty())
    {
        auto & [s, a] = q_t.front();
        auto & [t, b] = q_a.front();

        d_t.emplace_back(s);
        d_a.emplace_back(t);

        int len = min(a, b);
        move_len.emplace_back(len);
        a -= len, b -= len;
        if (a == 0) q_t.pop();
        if (b == 0) q_a.pop();
    }

    // for (int i = 0; i < move_len.size(); ++i)
    // {
    //     cout << d_t[i] << " : " << d_a[i] << " -- " << move_len[i] << endl;
    // }

    ll ans = 0;
    unordered_map<char, int> r, c;
    r['U'] = -1, c['U'] = 0;
    r['D'] = +1, c['D'] = 0;
    r['L'] = 0, c['L'] = -1;
    r['R'] = 0, c['R'] = +1;
    for (int i = 0; i < move_len.size(); ++i)
    {
        if (r_a == r_t && c_a == c_t)
        {

            if (d_t[i] == d_a[i]) ans += move_len[i];
        }
        else if (r_a != r_t && c_a == c_t)
        {
            ll d = abs(r_t - r_a);
            if (d % 2 == 0 && d / 2 <= move_len[i])
            {
                ll temp_r_t = r_t + r[d_t[i]] * d / 2;
                ll temp_r_a = r_a + r[d_a[i]] * d / 2;
                if (temp_r_t == temp_r_a) ans += 1;
            }
        }
        else if (r_a == r_t && c_a != c_t)
        {
            ll d = abs(c_t - c_a);
            if (d % 2 == 0 && d / 2 <= move_len[i])
            {
                ll temp_c_t = c_t + c[d_t[i]] * d / 2;
                ll temp_c_a = c_a + c[d_a[i]] * d / 2;
                if (temp_c_t == temp_c_a) ans += 1;
            }
        }
        else
        {
            // 4. 判相交，使至少一个轴相同的步数，然后判断这个步数后是否相同
            ll d = abs(r_t - r_a);
            if (d <= move_len[i])
            {
                ll temp_r_t = r_t + r[d_t[i]] * d;
                ll temp_c_t = c_t + c[d_t[i]] * d;
                ll temp_r_a = r_a + r[d_a[i]] * d;
                ll temp_c_a = c_a + c[d_a[i]] * d;
                if (temp_r_t == temp_r_a && temp_c_t == temp_c_a) ans += 1;
            }
        }
        r_t += r[d_t[i]] * move_len[i];
        c_t += c[d_t[i]] * move_len[i];
        r_a += r[d_a[i]] * move_len[i];
        c_a += c[d_a[i]] * move_len[i];
        // cout << r_t << " " << c_t << " " << r_a << " " << c_a << endl;
    }
    cout << ans << '\n';
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