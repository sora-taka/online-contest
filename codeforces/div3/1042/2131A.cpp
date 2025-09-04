#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &e : a) cin >> e;
        for (int &e : b) cin >> e;
        int cnt = 1;
        for (int i = 0; i < n; i++)
        {
            cnt += max(0, a[i] - b[i]);
        }
        cout << cnt << '\n';
    }
    
}