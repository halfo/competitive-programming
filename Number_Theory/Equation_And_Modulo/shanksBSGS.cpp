int64 shanksBSGS (int64 a, int64 b, int64 m) {
    int64 n = (int64) sqrt (m + .0) + 1;
    int64 an = 1;
    vals.clear ();
    for (int64 i = 0; i < n; ++i) an = (an * a) % m;

    int64 cur = an;
    for (int64 i = 1; i <= n; ++i) {
        if (!vals.count (cur)) vals [cur] = i;
        cur = (cur * an) % m;
    }

    int64 ans = m + 2;
    cur = b;
    for (int64 i = 0; i <= n; ++i) {
        if (vals.count (cur)) ans = min (ans, vals [cur] * n - i);
        cur = (cur * a) % m;
    }
    return ans;
}
