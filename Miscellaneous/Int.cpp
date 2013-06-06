struct Int {
    int64 x;
    Int (int x) : x (int64 (x) % MOD) { if (x < 0LL) x += MOD; }
    Int (int64 x = 0LL) : x (x % MOD) { if (x < 0LL) x += MOD; }

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

    bool  operator <   (const Int &rhs) const { return x < rhs.x; }
    bool  operator >   (const Int &rhs) const { return x > rhs.x; }
    bool  operator <=  (const Int &rhs) const { return x <= rhs.x; }
    bool  operator >=  (const Int &rhs) const { return x >= rhs.x; }
    bool  operator !=  (const Int &rhs) const { return x != rhs.x; }
    bool  operator ==  (const Int &rhs) const { return x == rhs.x; }

    Int power (int64 n) const {
        if (!n) return get (1);
        const Int &a = *this;
        if (n & 1) return power (n - 1) * a;
        return (a * a).power (n >> 1);
    }

    Int modInv () const { return power (MOD - 2); }
};
