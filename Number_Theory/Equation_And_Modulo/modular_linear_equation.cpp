vector <int64> solutions;

inline int64 mod (int64 a, int64 m) { return (a %= m) < 0 ? (a + m) : a; }

int64 egcd (int64 a, int64 b, int64 &x, int64 &y) {
	int64 x_p = 0, y_p = 1, d = b;
	if (a) {
        d = egcd (b % a, a, x_p, y_p);
        x = y_p - (b / a) * (y = x_p);
	}
	return d;
}

void modular_linear_equation_solver (int64 a, int64 b, int64 n) {
  int64 x, y;
  solutions.clear ();
  int64 d = egcd (a, n, x, y);
  if (!(b % d)) {
    x = mod (x * (b / d), n);
    for (int64 i = 0; i < d; ++i) solutions.push_back (mod (x + i * (n / d), n));
  }
}
