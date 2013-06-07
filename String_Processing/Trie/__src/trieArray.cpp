// __init the data-structure in every case

int tot;
struct node {
    int endPos;
    int next [];

    node () {
        endPos = 0;
        memset (next, -1, sizeof next);
    }
} state [MAX_N];

void __init () { tot = 0; state [tot++] = node (); }
inline int hash (char ch) { return 0; }

void insert (char *str){
    int cur = 0;
    for (int i = 0; str [i]; ++i) {
        if (state [cur].next [hash (str [i])] == -1) {
            state [tot] = node ();
            state [cur].next [hash (str [i])] = tot++;
        }
        cur = state [cur].next [hash (str [i])];
    }
    ++state [cur].endPos;
}

void traverse (int cur) {
    for (int i = 0; i < 128; ++i) {
        if (state [cur].next [i] == -1) continue;
        traverse (state [cur].next [i]);
    }
}
