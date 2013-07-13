int st [MAX_N << 2];

struct RMQ {
    int Leaf;
    RMQ () {
        Leaf = 1 << (32 - __builtin_clz (N - 1));
        for (int i = 0; i < Leaf; ++i) st [Leaf + i] = i < N ? LCP [i] : INT_MAX;
        for (int i = Leaf - 1; i > 0; --i) st [i] = min (st [i << 1], st [i << 1 | 1]);
    }

    int GetMin (int L, int R) const {
        int res = INT_MAX;
        if (L > R) swap (L, R);
        for (L += Leaf, R += Leaf + 1; L < R; L >>= 1, R >>= 1) {
            if ((L & 1)) res = min (res, st [L++]);
            if ((R & 1)) res = min (res, st [--R]);
        }
        return res;
    }
};
