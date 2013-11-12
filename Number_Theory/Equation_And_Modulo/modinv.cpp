int64 egcd (int64 a, int64 b, int64 &x, int64 &y) {
	int64 x_p = 0, y_p = 1, d = b;
	if (a) {
        d = egcd (b % a, a, x_p, y_p);
        x = y_p - (b / a) * (y = x_p);
	}
	return d;
}

int64 modinv (int64 a, int64 b) {
    int64 x, y;
    if (egcd (a, b, x, y) > 1) return 0;
    return (x %= b) < 0 ? (x + b) : x;
}
