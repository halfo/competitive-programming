int c [MAX_N], LCP [MAX_N];

void kasaiLCP () {
    for (int i = 0; i < N; i++) c [SA [i]] = i;
    for (int i = 0, j, k = 0; i < N; LCP [c [i++]] = k)
        if (c [i] > 0) for (k ? k-- : 0, j = SA [c [i] - 1]; str [i + k] == str [j + k]; k++);
        else k = 0;
}
