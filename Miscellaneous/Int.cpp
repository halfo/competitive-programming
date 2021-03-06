struct Int {
    int64 x;
    Int (int _x) : x (int64 (_x) % MOD) { if (x < 0LL) x += MOD; }
    Int (int64 _x = 0LL) : x (_x % MOD) { if (x < 0LL) x += MOD; }

    static Int get (int x)   { Int temp (x); return temp; }
    static Int get (int64 x) { Int temp (x); return temp; }

    int64 operator () ()               const { return x; }
    Int   operator +  (const Int &rhs) const { return get (x + rhs.x); }
    Int   operator -  (const Int &rhs) const { return get (x - rhs.x); }
    Int   operator *  (const Int &rhs) const { return get (((x  % MOD) * (rhs.x % MOD)) % MOD); }
    Int   operator /  (const Int &rhs) const { return (*this) * rhs.modInv (); }
    Int  &operator += (const Int &rhs)       { return (*this) = *this + rhs; }
    Int  &operator -= (const Int &rhs)       { return (*this) = *this - rhs; }
    Int  &operator *= (const Int &rhs)       { return (*this) = *this * rhs; }
    Int  &operator /= (const Int &rhs)       { return (*this) = *this / rhs; }

    friend istream &operator >> (istream &istr, Int &temp) { istr >> temp.x; return istr; }
    friend ostream &operator << (ostream &ostr, Int &temp) { ostr << temp.x; return ostr; }

    Int power (int64 n) const {
        if (!n) return get (1);
        const Int &a = *this;
        if (n & 1) return power (n - 1) * a;
        return (a * a).power (n >> 1);
    }

    Int modInv () const { return power (MOD - 2); }
};
