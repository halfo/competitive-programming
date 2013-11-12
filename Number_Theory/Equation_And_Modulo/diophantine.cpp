int64 egcd (int64 a, int64 b, int64 &x, int64 &y) {
	int64 x_p = 0, y_p = 1, d = b;
	if (a) {
        d = egcd (b % a, a, x_p, y_p);
        x = y_p - (b / a) * (y = x_p);
	}
	return d;
}

bool diophantine (int64 a, int64 b, int64 c, int64 &x, int64 &y) {
	int64 g = egcd (abs (a), abs (b), x, y);
	if (c % g != 0) return false;
    x = (c / g) * (a < 0 ? -x : x);
    y = (c / g) * (b < 0 ? -y : y);
	return true;
}
