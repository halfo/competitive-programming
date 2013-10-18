bool flag [MAX_N + 1];
vector <int> prime;

void linearSieve () {
    prime.push_back (2);
    for (int i = 3; i <= MAX_N; i += 2) {
        if (!flag [i]) prime.push_back (i);
        for (int j = 1; j < (int) prime.size () && i * prime [j] <= MAX_N; ++j) flag [i * prime [j]] = true;
    }
}
