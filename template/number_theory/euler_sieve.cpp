#include <vector>

std::vector<int> euler_sieve(int n) {
    std::vector<int> prime; 
    std::vector<bool> sieve(n + 1, true); 
    sieve[0] = sieve[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (sieve[i]) prime.push_back(i);
        for (auto &e : prime) {
            if (1LL * e * i > n) break;
            sieve[e * i] = false;
            if (i % e == 0) break;
        }
    }
    return prime;
}
