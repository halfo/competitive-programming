size_t hashELF (string key) {
    size_t g, h = 0;
    for (size_t i = 0; key [i]; ++i) {
        h = (h << 4) + key [i];
        g = h & 0xf0000000L;
        if (g) h ^= (g >> 24);
        h &= ~g;
    }
    return h;
}
