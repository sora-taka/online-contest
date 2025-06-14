#include <algorithm>
#include <iterator>
#include <vector>

template <typename RandIter>
std::vector<int> z_algorithm(RandIter begin, RandIter end) {
    int n = std::distance(begin, end);
    std::vector<int> Z(n, 0);
    Z[0] = n;
    int Z_box_left = 0, Z_box_right = 0;
    for (int i = 1; i < n; ++i) {
        if (i < Z_box_right) Z[i] = std::min(Z[i - Z_box_left], Z_box_right - i);
        while (i + Z[i] < n && *(begin + Z[i]) == *(begin + i + Z[i])) Z[i]++;
        if (i + Z[i] > Z_box_right) Z_box_left = i, Z_box_right = i + Z[i];
    }
    return Z;
}

template <typename TgtRandIter, typename PatRandIter>
std::vector<int> extend_z_algorithm(TgtRandIter target_begin, TgtRandIter target_end, PatRandIter pattern_begin, PatRandIter pattern_end) {
    int n = std::distance(target_begin, target_end), m = std::distance(pattern_begin, pattern_end);
    auto Z = z_algorithm(pattern_begin, pattern_end);
    std::vector<int> extend_Z(n, 0);
    int Z_box_left = 0, Z_box_right = 0;
    for (int i = 0; i < n; ++i) {
        if (i < Z_box_right) extend_Z[i] = std::min(Z[i - Z_box_left], Z_box_right - i);
        while (i + extend_Z[i] < n && extend_Z[i] < m && *(target_begin + i + extend_Z[i]) == *(pattern_begin + extend_Z[i])) extend_Z[i]++;
        if (i + extend_Z[i] > Z_box_right) Z_box_left = i, Z_box_right = i + extend_Z[i];
    }
    return extend_Z;
}
