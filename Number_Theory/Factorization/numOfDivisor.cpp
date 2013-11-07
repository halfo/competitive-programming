int64 numOfDivisor (int64 n) {
    if (n < 1LL) return 0LL;
    int64 cnt = 0LL;
    int64 ret = 1LL;

    while (!(n & 1LL)) { n >>= 1LL; ++cnt; }
    ret *= (cnt + 1LL);

    for (int64 i = 3LL; i * i <= n; i += 2LL) {
        cnt = 0LL;
        while (!(n % i)) { n /= i; ++cnt; }
        ret *= (cnt + 1LL);
    }

    if (n > 1LL) ret <<= 1LL;
    return ret;
}
