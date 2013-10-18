char pat [MAX_N];
int  pi  [MAX_N];

int failureFunction () {
	int i, shift = 0;
	for (i = 2; pat [i - 1]; ++i) {
		while (shift > 0 && pat [shift] != pat [i - 1]) shift = pi [shift];
		if (pat [shift] == pat [i - 1]) ++shift;
		pi [i] = shift;
	}
	return i - 1;
}
