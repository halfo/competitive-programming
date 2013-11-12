int64 numOfPrimeFactor (int64 n) {
    if (n < 1LL) return 0LL;
    int64 cnt = 0LL;

    if (!(n & 1LL)) {
        ++cnt;
        while (!(n & 1LL)) n >>= 1LL;
    }

    for (int64 i = 3LL; i * i <= n; i += 2LL) if ((!(n % i))) {
        ++cnt;
        while (!(n % i)) n /= i;
    }

    if (n > 1LL) ++cnt;
    return cnt;
}
