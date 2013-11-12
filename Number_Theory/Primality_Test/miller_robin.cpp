int64 mulModulo (int64 a, int64 b, int64 c) {
    int64 x = 0LL;
    int64 y = a % c;
    while (b > 0LL) {
        if (b & 1LL) x = (x + y) % c;
        y = (y << 1LL) % c;
        b = b >> 1LL;
    }
    return x;
}

int64 modulo (int64 a, int64 b, int64 c) {
    int64 x = 1LL;
    int64 y = a % c;
    while (b > 0LL) {
        if (b & 1LL) x = mulModulo (x, y, c);
        y = mulModulo (y, y, c);
        b = b >> 1LL;
    }
    return x;
}

bool millerRobin (int64 n) {
    if (n < 2LL) return false;
    if (n == 2LL) return true;
    if (!(n & 1LL)) return false;

    int64 s = n - 1LL;
    while (!(s & 1LL)) s >>= 1LL;

    // iteration = 20 is enough for LLONG
    for (int i = 0; i <= 20; ++i) {
        int64 a = rand () % (n - 1LL) + 1LL;
        int64 temp = s;
        int64 mod = modulo (a, temp, n);
        while (temp != n - 1LL && mod != 1LL && mod != n - 1LL) {
            mod = mulModulo (mod, mod, n);
            temp = temp << 1LL;
        }
        if (mod != n - 1LL && !(temp & 1LL)) return false;
    }
    return true;
}
