// Includes
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
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
#define popcount __builtin_popcountll
#define log2(x) ((x == 0) ? 0 : 63 - __builtin_clzll(x))
#define nl "\n"

inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
inline ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

mt19937_64 rng;

int randint(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

struct solution {
    void solve(int n, vi &a) {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += a[i];
        }
        // print output to stderr
        cerr << ans << nl;
    }
} sol;

vi randGen(int n, int lo = -1e9, int hi = 1e9) {
    vi a(n);
    for (int i = 0; i < n; i++) {
        a[i] = randint(lo, hi);
    }
    return a;
}

void printArr(vi &a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << nl;
}

int32_t main(int argc, char *argv[]) {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll seed = 0;
    // Gen seed based on generator args
    rng.seed(seed);
    int batch = atoi(argv[1]), test = atoi(argv[2]);
    int n;
    vi a;
    if (batch == 1) {
        n = 10;
        a = randGen(n, 1, n);
    } else if (batch == 2) {
        n = 1e6;
        a = randGen(n, 1, n);
    }
    // Print input to stdout
    cout << n << nl;
    printArr(a);
    sol.solve(n, a);
    return 0;
}