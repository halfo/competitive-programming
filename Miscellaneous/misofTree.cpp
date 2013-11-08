int N, tree [MAX_N];
void setN   (int max_ai) { N = 1 << (32 - __builtin_clz (max_ai)); } // max_ai = max (ai);
void insert (int x) { for (int i = N + x; i; i >>= 1) ++tree [i]; }
void erase  (int x) { for (int i = N + x; i; i >>= 1) --tree [i]; }
int getKTh  (int kTh, int i = -1) {
    if (kTh > tree [1]) return i;
	for (i = 1; i < N; i <<= 1) if (kTh > tree [i]) kTh -= tree [i++];
    return i + (kTh > tree [i]) - N;
}
