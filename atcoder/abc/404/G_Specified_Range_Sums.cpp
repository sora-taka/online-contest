#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int a[1000'005], cnt[10'005];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    long long maxn = 0, sum = 0;
    for (int i = 0; i <= 10'000; ++i)
    {
        if (cnt[i] == 0) continue;
        sum = 0;
        for (int j = 0; j <= 10'000; ++j)
        {
            sum += 1ll * abs(i - j) * cnt[j];
        }
        maxn = max(maxn, sum);
    }
    cout << maxn;
    return 0;
}

