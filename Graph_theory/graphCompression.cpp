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
    for (int i = 0; i < n; ++i) m [Find (i)]; // initialized and normalized (now p [i] holds the root of its component)
    int cnt = 0; // number of components, that is number of nodes in the new graph
    foreach (i, m) i -> second = cnt++; // given each component a number starting from 0
    for (int i = 0; i < n; ++i) p [i] = m [p [i]];

    for (int i = 0; i < cnt; ++i) newList [i].clear ();
    for (int u = 0; u < n; ++u) foreach (v, adjList [u]) {
        if (p [u] == p [*v]) continue; // to avoid self-loop
        newList [p [u]].pb (p [*v]);
    }
    n = cnt;
}
