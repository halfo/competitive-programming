int64 factmod (int64 n, int64 p) {
	int64 ans = 1LL;
	while (n > 1) {
		ans = (ans * ((n / p) % 2 ? p - 1 : 1)) % p;
		for (int64 i = 2; i <= n % p; ++i) ans = (ans * i) % p;
		n /= p;
	}
	return ans % p;
}
