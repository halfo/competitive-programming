// for up to 10 ^ 8, time :: 3.5s

unsigned flag [MAX_N / 64 + 1];
unsigned tot, primes [5761456];

inline bool isSet (unsigned i) { return flag [i >> 6] & (1 << ((i >> 1) & 31)); }
inline void setIt (unsigned i) { flag [i >> 6] |= (1 << ((i >> 1) & 31)); }

void linearSieve () {
    primes [tot++] = 2;
    for (unsigned i = 3; i <= MAX_N; i += 2) {
        if (!isSet (i)) primes [tot++] = i;
        for (unsigned j = 1; j < tot && i * primes [j] <= MAX_N; ++j) setIt (i * primes [j]);
    }
}
