inline double F (double x) {}
double simpson (double a, double b) {
    double ret = 0;
    double N   = int (1e6); // N must be even
    double h   = (b - a) / N;

    for (int i = 0; i <= N; ++i) {
        double x = a + h * i;
        ret += F (x) * ((i == 0 || i == N) ? 1 : (i & 1) ? 4 : 2);
    }
    return ret;
}
