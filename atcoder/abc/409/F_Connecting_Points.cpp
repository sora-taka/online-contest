#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

namespace atcoder
{

    // Implement (union by size) + (path compression)
    // Reference:
    // Zvi Galil and Giuseppe F. Italiano,
    // Data structures and algorithms for disjoint set union problems
    struct dsu
    {
    public:
        dsu() : _n(0) {}
        explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

        int merge(int a, int b)
        {
            assert(0 <= a && a < _n);
            assert(0 <= b && b < _n);
            int x = leader(a), y = leader(b);
            if (x == y)
                return x;
            if (-parent_or_size[x] < -parent_or_size[y])
                std::swap(x, y);
            parent_or_size[x] += parent_or_size[y];
            parent_or_size[y] = x;
            return x;
        }

        bool same(int a, int b)
        {
            assert(0 <= a && a < _n);
            assert(0 <= b && b < _n);
            return leader(a) == leader(b);
        }

        int leader(int a)
        {
            assert(0 <= a && a < _n);
            return _leader(a);
        }

        int size(int a)
        {
            assert(0 <= a && a < _n);
            return -parent_or_size[leader(a)];
        }

        std::vector<std::vector<int>> groups()
        {
            std::vector<int> leader_buf(_n), group_size(_n);
            for (int i = 0; i < _n; i++)
            {
                leader_buf[i] = leader(i);
                group_size[leader_buf[i]]++;
            }
            std::vector<std::vector<int>> result(_n);
            for (int i = 0; i < _n; i++)
            {
                result[i].reserve(group_size[i]);
            }
            for (int i = 0; i < _n; i++)
            {
                result[leader_buf[i]].push_back(i);
            }
            result.erase(
                std::remove_if(result.begin(), result.end(),
                               [&](const std::vector<int> &v)
                               { return v.empty(); }),
                result.end());
            return result;
        }

    private:
        int _n;
        // root node: -1 * component size
        // otherwise: parent
        std::vector<int> parent_or_size;

        int _leader(int a)
        {
            if (parent_or_size[a] < 0)
                return a;
            return parent_or_size[a] = _leader(parent_or_size[a]);
        }
    };

} // namespace atcoder

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<pii> p(n);
    atcoder::dsu dsu(n + q);
    for (auto &[x, y] : p) cin >> x >> y;
        

    using edge = tuple<int, int, int>;
    auto cmp = [](const edge &a, const edge &b) -> bool
    {
        return get<0>(a) > get<0>(b);
    };
    priority_queue<edge, vector<edge>, decltype(cmp)> pq(cmp);
    auto d = [&](int a, int b) -> int
    {
        return abs(p[a].first - p[b].first) + abs(p[a].second - p[b].second);
    };
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            pq.push({d(i, j), i, j});
        }
    }
    while (q--)
    {
        char op;
        cin >> op;
        if (op == '1')
        {
            int x, y;
            cin >> x >> y;
            n++;
            p.push_back({x, y});
            for (int i = 0; i < n - 1; ++i)
            {
                pq.push({d(i, n - 1), i, n - 1});
            }
        }
        else if (op == '2')
        {
            int k = -1;
            while (!pq.empty())
            {
                auto [d, a, b] = pq.top();
                pq.pop();
                if (!dsu.same(a, b))
                {
                    k = d;
                    dsu.merge(a, b);
                    while (!pq.empty() && get<0>(pq.top()) == k)
                    {
                        auto [d, a, b] = pq.top();
                        pq.pop();
                        if (!dsu.same(a, b)) dsu.merge(a, b);
                    }
                    break;
                }
            }
            cout << k << '\n';
        }
        else
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            cout << (dsu.same(u, v) ? "Yes" : "No") << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}