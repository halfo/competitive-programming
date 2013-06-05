char str [MAX_N], pat [MAX_N];
int N, M, pi [MAX_N];
vector <int> occurance;

int failureFunction () {
    int i, shift = 0;
    for (i = 2; pat [i - 1]; ++i) {
        while (shift > 0 && pat [shift] != pat [i - 1]) shift = pi [shift];
        if (pat [shift] == pat [i - 1]) ++shift;
        pi [i] = shift;
    }
    return i - 1;
}

int KMP () {
    int i, shift = 0;
    occurance.clear ();
    M = failureFunction ();

    for (i = 0; str [i]; ++i) {
        while (shift > 0 && pat [shift] != str [i] ) shift = pi [shift];
        if (pat [shift] == str [i]) ++shift;
        if (shift == M) {
            occurance.push_back (i - M + 1);
            shift = pi [shift];
        }
    }
    return i;
}
