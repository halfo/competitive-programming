const int INF = 0x2a; // 7 x 10 ^ 8 (must be INF < INT_MAX / 2)

int d [MAX_N][MAX_N], i_node [MAX_N][MAX_N];

void init () { ms (d, INF); ms (i_node, -1); }
void floyd_warshall (int n) {
    rep (i, n) d [i][i] = 0;
    rep (k, n) rep (i, n) rep (j, n) if (d [i][j] < d [i][k] + d [k][j]) {
        d [i][j] = d [i][k] + d [k][j];
        i_node [i][j] = k;
    }
}

void print_path (int i, int j, bool last = true) {
    if (i_node [i][j] == -1) {
        printf ("(%d, %d, %d)", i, j, d [i][j]);
        if (!last) printf (" -> ");
    } else {
        print_path (i, i_node [i][j], false);
        print_path (i_node [i][j], j, last & 1);
    }
}
