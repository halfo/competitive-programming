const int LOG_MAX = 22;

int SP[LOG_MAX][MAX_N];

void init_lca() { RST(SP); }

void build_lca(int u, int parent) {
    SP[0][u] = parent;
    FOR(i, LOG_MAX - 1)
        parent = SP[i][u] = SP[i - 1][parent];
}

int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    PER(i, LOG_MAX) {
        int pu = SP[i][u];
        if (pu == -1 || depth[pu] < depth[v]) continue;
        u = SP[i][u];
    }

    if (u == v) return u;

    PER(i, LOG_MAX) {
        if (SP[i][u] != SP[i][v]) {
            u = SP[i][u], v = SP[i][v];
        }
    }

    return SP[0][u];
}

int get_ancestor(int u, int k) {
    REP(i, LOG_MAX) {
        if (k & (1 << i))
            u = SP[i][u];
    }

    return u;
}
