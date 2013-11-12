/**
 * Shank's Baby-step Giant-step algorithm
 * runtime : sqrt (modValue) log modValue, but int practice sqrt (modValue)
 * a ^ x = b (mod m)
 * where a and m are co-prime, returns x
 */

map <int64, int64> vals;

int64 shanksBSGS (int64 a, int64 b) {
    int64 n = (int64) sqrt (mod + .0) + 1;
    int64 an = 1;
    vals.clear ();
    rep (i, n) an = (an * a) % mod;

    int64 cur = an;
    For (i, n) {
        if (!vals.count (cur)) vals [cur] = i;
        cur = (cur * an) % mod;
    }

    int64 ans = mod + 2;
    cur = b;
    rep (i, n + 1) {
        if (vals.count (cur)) ans = min (ans, vals [cur] * n - i);
        cur = (cur * a) % mod;
    }
    return ans;
}
