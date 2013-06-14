bool flag [MAX_N];
vector <int> prime;

void sieve () {
    prime.push_back (2);
    for (int i = 3; i < MAX_N; i += 2) {
        if (flag [i]) continue;
        prime.push_back (i);
        if (1LL * i * i < MAX_N) for (int j = i * i; j < MAX_N; j += 2 * i) flag [j] = true;
    }
}
