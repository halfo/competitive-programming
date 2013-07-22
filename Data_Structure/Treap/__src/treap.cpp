struct node {
	int64 key, rnk, cnt;
	node *le, *ri;

	node (int64 key = 0, int64 rnk = rand ()) : key (key), rnk (rnk), cnt (1), le (0), ri (0) {}
};

class treap {
	typedef node* pNode;
	pNode root;

    int64 count (pNode temp) { return temp ? temp -> cnt : 0; }
    void updateCnt (pNode temp) { if (temp) temp -> cnt = 1 + count (temp -> le) + count (temp -> ri); }

	void split (pNode temp, pNode &le, pNode &ri, int64 key) {
		if (!temp) { le = ri = 0; return; }
        if (key < temp -> key ) split (temp -> le, le, temp -> le, key), ri = temp;
        else split (temp -> ri, temp -> ri, ri, key), le = temp;
        updateCnt (temp);
    }

    void merge (pNode &temp, pNode le, pNode ri) {
        if (!le || !ri) temp = le ? le : ri;
        else if (le -> rnk > ri -> rnk) merge (le -> ri, le -> ri, ri), temp = le;
        else merge (ri -> le, le, ri -> le), temp = ri;
        updateCnt (temp);
    }

    void insert (pNode &temp, pNode it) {
        if (!temp) temp = it;
        else if (it -> rnk > temp -> rnk) split (temp, it -> le, it -> ri, it -> key), temp = it;
        else insert ((it -> key < temp -> key) ? temp -> le : temp -> ri, it);
        updateCnt (temp);
    }

    void erase (pNode &temp, int64 key, int64 rnk) {
        if (!temp) return;
        if (temp -> key == key) {
        	if (rnk == -1) rnk = temp -> rnk;
        	if (rnk == temp -> rnk) merge (temp, temp -> le, temp -> ri);
        	else erase (temp -> ri, key, rnk);
        } else erase ((key < temp -> key) ? temp -> le : temp -> ri, key, rnk);
        updateCnt (temp);
    }

    int64 countLess (pNode temp, int64 key) {
        if (!temp) return 0;
        if (key <= temp -> key) return countLess (temp -> le, key);
        return 1 + count (temp -> le) + countLess (temp -> ri, key);
    }

    int64 countLessEqual (pNode temp, int64 key) {
        if (!temp) return 0;
        if (key < temp -> key) return countLessEqual (temp -> le, key);
        return 1 + count (temp -> le) + countLess (temp -> ri, key);
    }

    int64 countEqual (pNode temp, int64 key) {
    	if (!temp) return 0;
    	if (key == temp -> key) return 1 + countEqual (temp -> ri, key);
    	return countEqual (key < temp -> key ? temp -> le : temp -> ri, key);
    }

    pNode getKth (pNode temp, const int K) {
        if (!temp or K >= count (temp)) return 0;
        if (K == count (temp -> le)) return temp;
        return K < count (temp -> le) ? getKth (temp -> le, K) : getKth (temp -> ri, K - (count (temp -> le) + 1));
    }

public:
	treap () { root = 0; srand (time (0)); }
	int64 size () { return count (root); }
	bool find (int64 key) { return countEqual (root, key) ? true : false; }
	void insert (int64 key, int64 rnk = rand ()) { insert (root, new node (key, rnk)); }
	void insert_unique (int64 key, int64 rnk = rand ()) { if (!countEqual (root, key)) insert (root, new node (key, rnk)); }
	void erase (int64 key, int64 rnk = -1) { erase (root, key, rnk); }
	int64 operator [] (const int idx) { pNode temp = getKth (root, idx); return temp ? temp -> key : LLONG_MIN; }
};
