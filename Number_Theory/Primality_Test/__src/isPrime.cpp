bool isPrime (long long n) {
    if (n < 2) return false;
    if (!(n & 1) && n != 2) return false;
    for (long long i = 3; i * i <= n; i += 2) if (!(n % i)) return false;
    return true;
}
