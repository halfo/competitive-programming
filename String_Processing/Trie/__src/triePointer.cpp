// __init and delete the data-structure in every case

struct node {
    bool endPos;
    node *next [128];

    node () {
        endPos = false;
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
    cur -> endPos = true;
}

void travarse (node *cur) {
    for (int i = 0; i < 128; ++i) {
        if (cur -> next [i] == NULL) continue;
        travarse (cur -> next [i]);
        // delete cur -> next;
    }
}
