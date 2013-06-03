// #include <stdlib.h>
typedef unsigned long long int64u;

int64u mulModulo (int64u a, int64u b, int64u c) {
    int64u x = 0;
    int64u y = a % c;
    while (b > 0) {
        if (b & 1) x = (x + y) % c;
        y = (y << 1) % c;
        b = b >> 1;
    }
    return x;
}

int64u modulo (int64u a, int64u b, int64u c) {
    int64u x = 1;
    int64u y = a % c;
    while(b>0) {
        if (b & 1) x = mulModulo (x, y, c);
        y = mulModulo (y, y, c);
        b = b >> 1;
    }
    return x;
}

bool millerRobin (int64u n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (!(n & 1)) return false;

    int64u s = n - 1;
    while (!(s&1)) s >>= 1;

    // iteration = 20 is enough for LLONG
    for (int i = 0; i <= 20; ++i) {
        int64u a = rand () % (n - 1) + 1;
        int64u temp = s;
        int64u mod = modulo (a, temp, n);
        while (temp != n - 1 && mod != 1 && mod != n - 1) {
            mod = mulModulo (mod, mod, n);
            temp = temp << 1;
        }
        if (mod != n - 1 && !(temp & 1)) return false;
    }
    return true;
}
