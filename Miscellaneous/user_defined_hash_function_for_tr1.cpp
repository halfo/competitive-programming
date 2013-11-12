// user defined hash function for unordered_set and unordered_map
// to avoid collision, use another hash function along with this one

struct hashJSW {
    // the return type always has to be size_t
    size_t operator () (const string &key) const {
        size_t h = 16777551;
        for (size_t i = 0; key [i]; ++i) h = (h << 1 | h >> 31) ^ size_t (key [i]);
        return h;
    }
};

int main () {
    string fruits [] = {"mango", "orange", "banana", "blueberry"};
    tr1::unordered_set <string, hashJSW> s;
    tr1::unordered_map <string, int, hashJSW> m;

    rep (i, 4) s.insert (fruits [i]), m [fruits [i]] = rand ();

    foreach (i, s) cout << *i << endl; cout << endl;
    foreach (i, m) cout << i -> first << " " << i -> second << endl;
    return 0;
}
