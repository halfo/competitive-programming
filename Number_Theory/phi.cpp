int64 phi (int64 n) {
	int64 ret = n;
	for (int64 i = 2; i * i <= n; ++i)
		if (!(n % i)) {
			while (!(n % i)) n /= i;
			ret -= ret / i;
		}
	if (n > 1LL) ret -= ret / n;
	return ret;
}
