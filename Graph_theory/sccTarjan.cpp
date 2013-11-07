// each component of dsu represents a unique scc
// a node can't be two different sccs' component, as those two will form a single scc

bool inCompStack [MAX_N];
int n, dfsnext, dfsn [MAX_N], mindfsn [MAX_N];
int nCompStack, compStack [MAX_N];
vector <int> adjList [MAX_N];
vector <int> newList [MAX_N];
map <int, int> m;

// Union-Find.
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

// change newList [] from vector to set if edges from component A to B needed to be considered as a single edge
void compress () {
    m.clear ();
    rep (i, n) m [Find (i)]; // initialized and normalized (now p [i] holds the root of its component)
    int cnt = 0; // number of components, that is number of nodes in the new graph
    foreach (i, m) i -> second = cnt++; // given each component a number starting from 0
    rep (i, n) p [i] = m [p [i]];

    rep (i, cnt) newList [i].clear ();
    rep (u, n) foreach (v, adjList [u]) {
        if (p [u] == p [*v]) continue; // to avoid self-loop
        newList [p [u]].pb (p [*v]);
    }
    n = cnt;
}

// nodes are indexed from 0
void scc () {
    nCompStack = dfsnext = 0;
    rep (i, n) dfsn [p [i] = i] = inCompStack [i] = 0;
    rep (i, n) if (!dfsn [i]) dfs (i);
    compress ();
}
