// each component of dsu represents a unique scc
// a node can't be two different sccs' component, as those two will form a single scc

bool inCompStack [MAX_N];
int n, dfsnext, dfsn [MAX_N], mindfsn [MAX_N];
int nCompStack, compStack [MAX_N];
vector <int> adjList [MAX_N];

// dsu
int p [MAX_N];
inline int Find (int x) { return p [x] == x ? x : p [x] = Find (p [x]); }
inline bool isSameset (int x, int y) { return Find (x) == Find (y); }
void Union (int x, int y) { p [Find (x)] = Find (y); }

void dfs (int u) {
    dfsn [u] = mindfsn [u] = ++dfsnext;
    inCompStack [compStack [nCompStack++] = u] = true;

    foreach (i, adjList [u]) {
        if (!dfsn [*i]) dfs (*i);
        if (inCompStack [*i]) mindfsn [u] = min (mindfsn [u], mindfsn [*i]);
    }

    // found (the root of) an scc
    if (dfsn [u] == mindfsn [u]) do {
        Union (u, compStack [--nCompStack]);
        inCompStack [compStack [nCompStack]] = false;
    } while (compStack [nCompStack] != u);
}

// nodes are indexed from 0
void scc () {
    nCompStack = dfsnext = 0;
    for (int i = 0; i < n; ++i) dfsn [p [i] = i] = inCompStack [i] = 0;
    for (int i = 0; i < n; ++i) if (!dfsn [i]) dfs (i);
}
