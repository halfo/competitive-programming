int lcp (int u, int v) {
    int ret = 0;
    for (int i = stp; i >= 0; --i) if (rank [i][u] == rank [i][v]) ret += 1 << i, u += 1 << i, v += 1 << i;
    return ret;
}
