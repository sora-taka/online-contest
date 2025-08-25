#include <bits/stdc++.h>

#ifndef ATCODER_DSU_HPP
#define ATCODER_DSU_HPP 1

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1), isBlack(n, false), BlackNum(n, 0) {}

    void change (int a)
    {
        if (isBlack[a])
        {
            BlackNum[leader(a)]--;
        }
        else
        {
            BlackNum[leader(a)]++;
        }
        isBlack[a] = !isBlack[a];
    }

    bool toblack(int a)
    {
        int x = leader(a);
        return BlackNum[x] > 0;
    }

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        BlackNum[x] = BlackNum[x] + BlackNum[y];
        BlackNum[y] = BlackNum[x];
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    
    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        return _leader(a);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
    std::vector<bool> isBlack;
    std::vector<int> BlackNum;

    int _leader(int a) {
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = _leader(parent_or_size[a]);
    }
};

}  // namespace atcoder

#endif  // ATCODER_DSU_HPP


using namespace std;

using ll = long long;
using pii = pair<int, int>;
void solve()
{
    int n, q;
    cin >> n >> q;
    atcoder::dsu d(n);
    while (q--)
    {
        char c;
        cin >> c;
        if (c == '1')
        {
            int a, b;
            cin >> a >> b;
            d.merge(a - 1, b - 1);
        }
        else if (c == '2')
        {
            int a;
            cin >> a;
            d.change(a - 1);
        }
        else
        {
            int a;
            cin >> a;
            cout << (d.toblack(a - 1) ? "Yes" : "No") << '\n';
        }
    }
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