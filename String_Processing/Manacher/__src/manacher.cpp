char str [MAX_N], modStr [MAX_N << 1];
int  pal [MAX_N << 1];

int preProcess () {
    int len = 2;
    strcpy (modStr, "^#");

    for (int i = 0; str [i]; i++) {
        modStr [len++] = str [i];
        modStr [len++] = '#';
    }
    modStr [len++] = '$';
    modStr [len++] = 0;

    return len;
}

void manacher () {
    int C = 0, R = 0;
    int N = preProcess ();

    for (int i = 1; i < N - 1; ++i) {
        int i_mirror = 2 * C - i;
        pal [i] = (R > i) ? min (R - i, pal [i_mirror]) : 0;
        while (modStr [i + 1 + pal [i]] == modStr [i - 1 - pal [i]]) ++pal [i];
        if (i + pal [i] > R) C = i, R = i + pal [i];
    }
}
