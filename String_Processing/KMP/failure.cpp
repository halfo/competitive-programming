char pat [MAX_N];
int  pi  [MAX_N];

int failure () {
	int i, shift = 0;
	for (i = 2; pat [i - 1]; ++i) {
		while (shift > 0 && pat [shift] != pat [i - 1]) shift = pi [shift];
		pi [i] = shift += (pat [shift] == pat [i - 1]);
	}
	return i - 1;
}
