#include <bits/stdc++.h>

#include <fstream>
using namespace std;

// #define int long long

bool DEBUG = 1;
#define deb(x) \
    if (DEBUG) cout << #x << " " << x << "\n";

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ppi pair<pii, int>
#define pip pair<int, pii>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vb vector<bool>
#define vpi vector<pii>
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
#define uset unordered_set
#define umap unordered_map
#define loop(i, s, e) for (int i = s; i <= e; i++)
#define loopd(i, s, e) for (int i = s; i >= e; i--)
#define nl "\n"
#define popcount __builtin_popcountll
#define log2(x) ((x == 0) ? 0 : 63 - __builtin_clzll(x))

inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
inline ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

/*
WA??
SAMPLES AND EXAMPLES - REREAD - EDGE CASES
int overflow
array bounds(can WA, access random stuff)
special cases n=1, n=0,
missed small detail
cant compile == MLE
cant do ms on doubles
try FAST SLOW?

STRATEGIES:
Invariants, Binary Search, SQRT distinct, Surprise Graph
Characteristics of the optimal solution
Recall - Specific to General - Guess - Think like a problem - Pick a Method - Google - Print Out and Look

IMPORTANT:
AVOID SUNK COST FALLACY
WRITE STUFF DOWN - IDEA SHEET - SAMPLES AND EXAMPLES - GO SLOW - DONT TUNNEL VISION - DONT SPAM SUB
DONT GUESS THINK MORE
WAIT AT LEAST 1 MIN B4 SUBMIT
*/
// ---------- TEMPLATE ----------

struct edge {
    ll x, y;
    bool operator<(const edge &o) const {
        if (x == o.x) return y < o.y;
        return x < o.x;
    }
};

const int MOD = 1e9 + 7;
// WRONG MOD??? 998244353
const int MAX = 2e5 + 5;
// CHECK MAX!!!

int a[MAX];

void solve(int n, int m) {
    ll x = 1LL * n * m;
    if (x % 2 == 0) {
        cout << x / 2 << " " << x / 2 << nl;
        return;
    }
    ll y = 1LL * (max(n, m) / 2 + 1) * min(n, m);
    cout << y << " " << x - y << nl;
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin>>T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        solve(n, m);
    }
    return 0;
}