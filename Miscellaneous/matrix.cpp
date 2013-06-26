template <int Odr> struct matrix {
    int64 M [Odr][Odr];

    matrix () { memset (M, 0, sizeof M); }
    matrix (int64 temp [Odr][Odr]) { memcpy (M, temp, sizeof M); }

    void toIdentity () {
        memset (M, 0, sizeof M);
        for (int i = 0; i < Odr; ++i) M [i][i] = 1LL;
    }
    void allOne () {
        for (int i = 0; i < Odr; ++i)
            for (int j = 0; j < Odr; ++j) M [i][j] = 1LL;
    }

    matrix <Odr> operator * (const matrix <Odr> &rhs) const {
        matrix <Odr> temp;
        for (int i = 0; i < Odr; ++i)
            for (int j = 0; j < Odr; ++j)
                for (int k = 0; k < Odr; ++k)
                    temp.M [i][j] += (M [i][k] * rhs.M [k][j]);
        return temp;
    }

    matrix <Odr> operator % (const int64 mod) const {
        matrix <Odr> temp;
        for (int i = 0; i < Odr; ++i)
            for (int j = 0; j < Odr; ++j)
                temp.M [i][j] = M [i][j] % mod;
        return temp;
    }

    matrix <Odr> pow (int64 power) {
        matrix <Odr> temp;
        matrix <Odr> base = *this;
        temp.toIdentity ();
        while (power) {
            if (power & 1LL) temp = (temp * base) % MOD;
            base = (base * base) % MOD;
            power >>= 1LL;
        }
        return temp % MOD;
    }

    friend ostream &operator << (ostream &ostr, matrix <Odr> &temp) {
        for (int i = 0; i < Odr; ++i) {
            if (i) cout << endl;
            for (int j = 0; j < Odr; ++j) ostr << temp.M [i][j] << " ";
        }
        return ostr;
    }
};
