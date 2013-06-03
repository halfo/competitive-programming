long long numOfDivisor (long long n) {
    if (n < 1) return 0;
    long long cnt = 0LL;
    long long ret = 1LL;

    while (!(n & 1)) { n >>= 1; ++cnt; }
    ret *= (cnt + 1LL);

    for (long long i = 3; i * i <= n; i += 2) {
        cnt = 0LL;
        while (!(n % i)) { n /= i; ++cnt; }
        ret *= (cnt + 1LL);
    }

    if (n > 1) ret <<= 1;
    return ret;
}
