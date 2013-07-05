int phi [MAX_N];

void sievePhi () {
	phi [1] = 1;
	for (int i = 2; i < MAX_N; ++i) if (phi [i] == 0) {
        phi [i] = i - 1;
        for (int j = i << 1; j < MAX_N; j += i) {
            if (phi [j] == 0) phi [j] = j;
            phi [i] = phi [j] / i * (i - 1);
        }
    }
}
