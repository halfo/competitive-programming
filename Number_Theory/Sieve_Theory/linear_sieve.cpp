bool flag [MAX_N + 1];
vector <int> primes;

void linearSieve () {
    primes.push_back (2);
    for (int i = 3; i <= MAX_N; i += 2) {
        if (!flag [i]) primes.push_back (i);
        for (int j = 1; j < (int) primes.size () && i * primes [j] <= MAX_N; ++j) flag [i * primes [j]] = true;
    }
}
