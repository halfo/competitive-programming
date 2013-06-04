bool isPrime (int64 n) {
    if (n < 2LL) return false;
    if (!(n & 1LL) && n != 2LL) return false;
    for (int64 i = 3LL; i * i * 1LL <= n; i += 2LL) if (!(n % i)) return false;
    return true;
}
