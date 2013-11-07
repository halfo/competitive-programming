int c [MAX_N], LCP [MAX_N];

void kasaiLCP () {
    for (int i = 0; i < N; ++i) c [SA [i]] = i;
    LCP [0] = 0;
    for (int i = 0, h = 0; i < N; ++i) if (c[i] > 0) {
            int j = SA [c [i] - 1];
            while (i + h < N && j + h < N && str [i + h] == str [j + h]) ++h;
            LCP [c [i]] = h;
            if (h > 0) --h;
        }
}
