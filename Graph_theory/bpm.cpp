bool seen [MAX_N];
int lhs [MAX_N], rhs [MAX_N];

bool kuhn (int u) {
    foreach (v, adjList [u]) if (!seen [*v]) {
        seen [*v] = true;

        if (rhs [*v] == -1 || kuhn (rhs [*v])) {
            rhs [*v] = u;
            lhs [u] = *v;
            return true;
        }
    }
    return false;
}

int bpm () {
    bool match;
    int ans = 0;
    rst (lhs); rst (rhs);
    do {
        clr (seen); match = false;
        for (int i = 0; i < n; ++i) if (lhs [i] == -1 && kuhn (i)) ans += (match = 1);
    } while (match);
    return ans;
}
