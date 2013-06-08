//{ ************[       Template       ]************
using namespace std;
//{ ************[      C headers       ]************
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <ctime>
//}
//{ ************[     C++ headers      ]************
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <complex>
//{ ************[     Test Report 1    ]************
#include <tr1/regex>
#include <tr1/unordered_set>
#include <tr1/unordered_map>
//}
//}
//{ ************[        Loops         ]************
#define forab(i, a, b) for (__typeof(b) i = (a); i <= (b); ++i)
#define rep(i, n) forab (i, 0, (n) - 1)
#define For(i, n) forab (i, 1, n)
#define rofba(i, a, b) for (__typeof(b) i = (b); i >= (a); --i)
#define per(i, n) rofba (i, 0, (n) - 1)
#define rof(i, n) rofba (i, 1, n)
#define forstl(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
//}
//{ ************[   Floating points    ]************
#define EPS DBL_EPSILON
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2 * acos (0.0)
//}
//{ ************[        Macros        ]************
#define mem(a, i) memset ((a), i, sizeof ((a)))
#define clr(a) mem ((a), 0)
#define all(a) (a).begin (), (a).end ()
#define pb push_back

template <class T> T max (T &a, T &b) { return a > b ? a : b; }
template <class T> T min (T &a, T &b) { return a < b ? a : b; }
//}
//{ ************[  Typedefs && Consts  ]************
typedef long long int64;
typedef unsigned long long int64u;

const int MAX_N = int (1e6) + 7;
const int MOD   = int (1e9) + 7;
//}
//}

int main () {
	cin.sync_with_stdio (false);
#ifdef IOfromFile
	freopen ("input.txt", "r", stdin);
	// freopen ("output.txt", "w", stdout);
#endif

	return 0;
}
