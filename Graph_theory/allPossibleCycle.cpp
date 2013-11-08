bool seen [MAX_N];
int nV, cur, nCycle;
vector <int> stk, adjList [MAX_N], tempList [MAX_N];

inline bool inList (vector <int> &uList, int v) { foreach (it, uList) if (*it == v) return true; return false; }
bool notSeen (int u) { seen [u] = false; foreach (v, tempList [u]) if (seen [*v]) notSeen (*v); tempList [u].clear (); }

bool calCycle (int u) {
	bool isCycle = false;
	seen [u] = true;
	stk.push_back (u);

	foreach (v, adjList [u]) {
		if (*v < cur) continue;
		if (*v == cur) {
			// print or copy the nodes of cycle, length histogram, longest cycle, vertex popularity
			nCycle += (isCycle = true);
		} else if (!seen [*v]) isCycle = calCycle (*v);
	}

	if (isCycle) notSeen (u);
	else foreach (v, adjList [u]) {
		if (*v < cur) continue;
		if (!inList (tempList [*v], u)) tempList [*v].push_back (u);
	}

	stk.pop_back ();
	return isCycle;
}

void  hawickJames () {
	stk.clear ();
	for (cur = nCycle = 0; cur < nV; ++cur) {
        memset (seen, false, sizeof seen);
        for (int i = 0; i < MAX_N; ++i) tempList [i].clear ();
        calCycle (cur);
    }
}
