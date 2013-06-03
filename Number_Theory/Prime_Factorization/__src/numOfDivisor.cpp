long long numOfDivisor (long long n) {
    if (n < 1LL) return 0LL;
    long long cnt = 0LL;
    long long ret = 1LL;

    while (!(n & 1LL)) { n >>= 1LL; ++cnt; }
    ret *= (cnt + 1LL);

    for (long long i = 3LL; i * i <= n; i += 2LL) {
        cnt = 0LL;
        while (!(n % i)) { n /= i; ++cnt; }
        ret *= (cnt + 1LL);
    }

    if (n > 1LL) ret <<= 1LL;
    return ret;
}
