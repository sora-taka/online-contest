#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void slove()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> l(n + 1), r(n + 2);
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '1')
        {
            cnt++;
            l[i + 1] = l[i];
        }
        else
        {
            if (cnt > 0) l[i + 1] = l[i] + 1, cnt--;
            else l[i + 1] = l[i];
            
        }
    }
    cnt = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] == '1')
        {
            cnt++;
            r[i + 1] = r[i + 2];
        }
        else
        {
            if (cnt > 0) r[i + 1] = r[i + 2] + 1, cnt--;
            else r[i + 1] = r[i + 2];
        }
    }
    int minn = n;
    for (int i = 1; i <= n; ++i)
    {
        minn = min(minn, l[i] + r[i]);
    }
    cout << minn << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) slove();
}