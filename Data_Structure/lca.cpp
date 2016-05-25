// node starts from 0
const int LOG_MAX = 22;

int F[LOG_MAX][MAX_N];

void build_lca() {
    RST(F);

    REP(i, number of nodes) F[0][i] = parent[i];
    FOR(i, LOG_MAX - 1) {
        REP(j, number of nodes) {
            if (F[i - 1][j] == -1) continue;
            F[i][j] = F[i - 1][F[i - 1][j]];
        }
    }
}

// returns -1 if no lca is found
int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    PER(i, LOG_MAX) {
        int pu = F[i][u];
        if (pu == -1 || depth[pu] < depth[v]) continue;
        u = pu;
    }

    if (u == v) return u;

    PER(i, LOG_MAX) {
        if (F[i][u] != F[i][v]) {
            u = F[i][u], v = F[i][v];
        }
    }

    return F[0][u];
}

int get_ancestor(int u, int k) {
    REP(i, LOG_MAX) {
        if (k - (1 << i) < 0) continue;

        u = F[i][u];
        k -= 1 << i;
    }

    return u;
}
