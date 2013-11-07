// __init and delete the data-structure in every case
// its always better to use array version of trie

struct node {
    int endPos;
    node *next [128];

    node () {
        endPos = 0;
        memset (next, 0, sizeof next);
    }
} *root;

void __init () { root = new node (); }

void insert (char *str){
    node *cur = root;
    for (int i = 0; str [i]; ++i) {
        if (cur -> next [str [i]] == NULL)
            cur -> next [str [i]] = new node ();
        cur = cur -> next [str [i]];
    }
    ++cur -> endPos;
}

void dfs (node *cur) {
    for (int i = 0; i < 128; ++i) {
        if (cur -> next [i] == NULL) continue;
        dfs (cur -> next [i]);
        // delete cur -> next;
    }
}
