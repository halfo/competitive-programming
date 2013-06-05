const int64u P = 31;

char str [MAX_N], pat [MAX_N];
vector <int> occurance;

void karpRabin () {
    size_t strLen      = strlen (str);
    size_t patLen      = strlen (pat);
    size_t powLen      = max (strLen, patLen);
    int64u *primePow   = new int64u [powLen];
    int64u *prefixHash = new int64u [strLen];
    occurance.clear ();

    // Powers of P(rime)
    primePow [0] = 1;
    for (size_t i = 1; i < powLen; ++i) primePow [i] = primePow [i - 1] * P;

    // Hash of all prefixes of str
    for (size_t i = 0; i < strLen; ++i) {
        prefixHash [i] = (str [i] - 'a' + 1) * primePow [i];
        if (i) prefixHash [i] += prefixHash [i - 1];
    }

    // Hash of pat
    int64u patHash = 0ULL;
    for (size_t i = 0; i < patLen; ++i)
        patHash += (pat [i] - 'a' + 1) * primePow [i];

    for (size_t i = 0; i + patLen - 1 < strLen; ++i) {
        int64u cur_hash  = prefixHash [i + patLen - 1];
        if (i) cur_hash -= prefixHash [i - 1];
        if (cur_hash == patHash * primePow [i]) occurance.push_back (i);
    }
}
