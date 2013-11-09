vector <int> newList [MAX_N];
map <int, int> m;

// dsu
int p [MAX_N];
inline int Find (int x) { return p [x] == x ? x : p [x] = Find (p [x]); }
inline bool isSameset (int x, int y) { return Find (x) == Find (y); }
void Union (int x, int y) { p [Find (x)] = Find (y); }

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
