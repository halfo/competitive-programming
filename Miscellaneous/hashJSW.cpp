size_t hashJSW (const string &key) {
    size_t h = 16777551;
    for (size_t i = 0; key [i]; ++i) h = (h << 1 | h >> 31) ^ size_t (key [i]);
    return h;
}
