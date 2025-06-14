#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    double s;
    cin >> n >> s;
    double last = s + 0.5;
    bool f = 1;
    while (n--)
    {
        int t;
        cin >> t;
        if (t > last) f = 0;
        else last = t + s + 0.5;
    }
    if (f) cout << "Yes";
    else cout << "No";
}