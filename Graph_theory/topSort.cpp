int indegree [MAX_N];
vector <int> top;
queue <int> Q;

// runtime :: O (V + E)
// to count number of connected components, use dsu (or similar) explicitly
// don't use this code to find that or even to find if the graph is connected or not

void topSort () {
    top.clear ();
    for (int i = 0; i < n; ++i) if (!indegree [i]) Q.push (i);

	while (!Q.empty ()) {
	    // if (Q.size () > 1) then multiple solution may exist (as more then 1 way to start)
	    // depending on whether cycle exists or not
		int u = Q.front ();
		Q.pop ();
		foreach (v, adjList [u]) {
			--indegree [*v];
			if (!indegree [*v]) Q.push (*v);
		}
		top.push_back (u);
	}
	// if (top.size () < n) then cycle exists, so no topOrder is available
}
