int isSubstr (char *p) {
    int l = 0, sz = strlen (p), h = N - 1;

    while (l <= h) {
        int mid = l + (h - l) / 2;
        char *tmp = (char *) malloc (sz + 1);
        strncpy (tmp, str + SA [mid], sz);
        tmp [sz] = 0;
        int cmp = strcmp (p, tmp);
        if (cmp < 0) h = mid - 1;
        if (cmp > 0) l = mid + 1;
        if (!cmp) return mid;
    }
    return -1;
}
