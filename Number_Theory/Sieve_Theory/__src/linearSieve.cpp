bool flag [MAX_N + 1];
vector <int> prime;

void linearSieve () {
    flag [4] = 1;
    prime.clear ();
    prime.push_back (2);

    for (int i = 3; i <= MAX_N; i += 2) {
        if (!flag [i]) flag [i] = true, prime.push_back (i);
        for (int j = 0; j < (int) prime.size () && i * prime [j] <= MAX_N; ++j) flag [i * prime [j]] = true;
    }
}
