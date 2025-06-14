#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) , min_val(n, 2147483647){}

    int merge(int a, int b, int val) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        min_val[x] = min({min_val[x], val, min_val[y]});
        min_val[y] = min({min_val[x], val, min_val[y]});
        if (x == y) return x;
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
    int get_min_val(int a) {
        assert(0 <= a && a < _n);
        return min_val[_leader(a)];
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
    std::vector<int> min_val;
    int _leader(int a) {
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = _leader(parent_or_size[a]);
    }
};

}  // namespace atcoder

void solve()
{
    int n, m;
    cin >> n >> m;
    using edge = tuple<int, int, int>;
    auto cmp = [](edge x, edge y) {
        return get<2>(x) < get<2>(y);
    };
    vector<edge> g(m);
    for (auto &[u, v, w] : g) cin >> u >> v >> w, u--, v--;
    ranges::sort(g, cmp);
    atcoder::dsu dsu(n);
    int ans = 2147483647;
    for (auto &[u, v, w] : g) {
        if (!dsu.same(u, v))
        {
            dsu.merge(u, v, w);
        }

        if (dsu.same(0, n - 1)) {
            ans = min(dsu.get_min_val(0) + w, ans);
        } 
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);  
    cin.tie(0), cout.tie(0);  
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


