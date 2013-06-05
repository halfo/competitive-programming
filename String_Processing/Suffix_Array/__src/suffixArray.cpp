char str [MAX_N];
int N, stp, mv, SA [MAX_N], LCP [MAX_N], tmp [MAX_N];
int sum [MAX_N], cnt [MAX_N], c [MAX_N], rank [22][MAX_N];

inline bool cmp (const int &a, const int &b) { return str [a] < str [b]; }

bool isEqual (int u, int v) {
    if (!stp) return str [u] == str [v];
    if (rank [stp - 1][u] != rank [stp - 1][v]) return false;
    int a = u + mv < N ? rank [stp - 1][u + mv] : -1;
    int b = v + mv < N ? rank [stp - 1][v + mv] : -1;
    return a == b;
}

void update () {
    int rnk = 0;
    for (int i = 0; i < N; ++i) sum [i] = 0;
    for (int i = 0; i < N; ++i) {
        SA [i] = tmp [i];
        if (i && !isEqual (SA [i], SA [i - 1])) {
            rank [stp][SA [i]] = ++rnk;
            sum [rnk + 1] = sum [rnk];
        } else rank [stp][SA [i]] = rnk;
        ++sum [rnk + 1];
    }
}

void Sort () {
    for (int i = 0; i < N; ++i) cnt [i] = 0;
    memset (tmp, -1, sizeof tmp);
    for (int i = 0; i < mv; ++i) {
        int idx = rank [stp - 1][N - i - 1];
        int x = sum [idx];
        tmp [x + cnt [idx]] = N - i - 1;
        ++cnt [idx];
    }

    for (int i = 0; i < N; ++i) {
        int idx = SA [i] - mv;
        if (idx < 0) continue;
        idx = rank [stp - 1][idx];
        int x = sum [idx];
        tmp [x + cnt [idx]] = SA [i] - mv;
        ++cnt [idx];
    }
    update ();
    return;
}

void computeLCP () {
    for (int i = 0; i < N; ++i) c [SA [i]] = i;
    LCP [0] = 0;
    for (int i = 0, h = 0; i < N; ++i) if (c[i] > 0) {
            int j = SA [c [i] - 1];
            while (i + h < N && j + h < N && str [i + h] == str [j + h]) ++h;
            LCP [c [i]] = h;
            if (h > 0) --h;
        }
}

void suffixArray () {
    N = strlen (str);
    for (int i = 0; i < N; ++i) tmp [i] = i;
    sort (tmp, tmp + N, cmp);
    stp = 0;
    update ();
    ++stp;
    for (mv = 1; mv < N; mv <<= 1) {
        Sort ();
        ++stp;
    }
    --stp;
    for (int i = 0; i <= stp; i++)  rank [i][N] = -1;
    computeLCP();
}
