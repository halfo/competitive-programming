int64U nCr [MAX_N][MAX_N];

void pascal () {
    for (int i = 0; i < MAX_N; ++i) {
        nCr [i][0] = nCr [i][i] = 1ULL;
        for (int j = 1; j < i; ++j) nCr [i][j] = nCr [i - 1][j - 1] + nCr [i - 1][j];
    }
}
