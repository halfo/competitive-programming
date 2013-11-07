const int MAX_CHAR = int (52);
const int MAX_NODE = int (2e5) + 7;

int mark [MAX_NODE];
string str, pat [100];
queue <int> Q;

inline int val (char ch) { if (ch >= 'a') return ch - 97; return ch - 39;}

struct trie {
    int tot;

    struct node {
        bool endPos;
        int pi, edges [MAX_CHAR];

        void clear () {
            pi = endPos = 0;
            memset (edges, -1, sizeof edges);
        }
    } nodes [MAX_NODE];

    void __init () {
        tot = 1;
        nodes [0].clear ();
        memset (nodes [0].edges, 0, sizeof nodes [0].edges);
    }

    void insert (string temp) {
        int charVal, point = 0;
        for (int i = 0; temp [i]; ++i) {
            charVal = val (temp [i]);
            if (nodes [point].edges [charVal] <= 0) {
                nodes [point].edges [charVal] = tot;
                nodes [tot++].clear ();
            }
            point = nodes [point].edges [charVal];
        }
        nodes [point].endPos = true;
    }

    void computeFailure () {
        for (int i = 0; i < MAX_CHAR; ++i) if (nodes [0].edges [i])
                Q.push (nodes [0].edges [i]);

        while (!Q.empty ()) {
            int u = Q.front ();
            Q.pop ();
            for (int i = 0; i < MAX_CHAR; ++i) if (nodes [u].edges [i] != -1) {
                    int v = nodes [u].edges [i];
                    int findPi = nodes [u].pi;
                    while (nodes [findPi].edges [i] == -1) findPi = nodes [findPi].pi;
                    findPi = nodes [v].pi = nodes [findPi].edges [i];
                    nodes [v].endPos |= nodes [findPi].endPos;
                    Q.push (v);
                }
        }
    }
} trie;

void marker (int point) {
    while (trie.nodes [point].endPos) {
        ++mark [point];
        point = trie.nodes [point].pi;
    }
}

void ahoCorasick () {
    int charVal, point = 0;
    memset (mark, 0, sizeof (int) * trie.tot);
    for (int i = 0; str [i]; ++i) {
        charVal = val (str [i]);
        while (trie.nodes [point].edges [charVal] == -1)
            point = trie.nodes [point].pi;
        point = trie.nodes [point].edges [charVal];

        marker (point);
    }
}

int exists (string temp) {
    int point = 0;
    for (int i = 0; temp [i]; ++i)
        point = trie.nodes [point].edges [val (temp [i])];
    return mark [point];
}

void setTrie (int n) {
    trie.__init ();
    for (int i = 0; i < n; ++i) trie.insert (pat [i]);
    trie.computeFailure ();
    ahoCorasick ();
}
