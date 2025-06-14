long long binary_exp(long long base, long long exponent, long long mod) {
    long long result = 1;
    base %= mod;
    while (exponent > 0) {
        if (exponent & 1) result = (result * base) % mod; 
        exponent >>= 1;
        base = (base * base) % mod;
    }
    return result;
}

long long mod_inverse(long long number, long long prime_mod) {
    if (number % prime_mod == 0) return -1; 
    // By Fermat's Little Theorem: a^(p-2) ≡ a^(-1) (mod p)
    return binary_exp(number, prime_mod - 2, prime_mod);
}

long long mod_div(long long a, long long b, long long mod) {
    a %= mod;
    long long b_inv = mod_inverse(b, mod);
    if (b_inv == -1) return -1; 
    return (a * b_inv) % mod;
}

long long mod_add(long long a, long long b, long long mod) {
    a %= mod, b %= mod;
    return (a + b) % mod;
}

long long mod_sub(long long a, long long b, long long mod) {
    a %= mod, b %= mod;
    return (a - b + mod) % mod; 
}

long long mod_mul(long long a, long long b, long long mod) {
    a %= mod, b %= mod;
    return (a * b) % mod;
}
