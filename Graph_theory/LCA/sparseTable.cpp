// set lvl [] and par [] using dfs

int n, par [MAX_N], lvl [MAX_N], st [MAX_N][22];

void sparseTable () {
    memset (st, -1, sizeof st);

    for (int i = 0; i < n; ++i) st [i][0] = par [i];
    for (int j = 1; 1 << j < n; ++j) for (int i = 0; i < n; ++i)
        if (st [i][j - 1] != -1) st [i][j] = st [st [i][j - 1]][j - 1];
}

int query (int u, int v) {
    int log;
    if (lvl [u] < lvl [v]) swap (u, v);
    for (log = 0; 1 << (log + 1) <= lvl [u]; ++log);
    for (int i = log; i >= 0; --i) if (lvl [u] - (1 << i) >= lvl [v]) u = st [u][i];

    if (u == v) return u;

    for (int i = log; i >= 0; --i) if (st [u][i] != -1 && st [u][i] != st [v][i])
        u = st [u][i], v = st [v][i];

    return par [u];
}
