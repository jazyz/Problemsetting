#include <bits/stdc++.h>

#include <fstream>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define vl vector<ll>
#define vb vector<bool>
#define vpi vector<pll>
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
#define uset unordered_set
#define umap unordered_map
#define nl "\n"
#define popcount __builtin_popcountll
#define log2(x) ((x == 0) ? 0 : 63 - __builtin_clzll(x))

inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
inline ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

ll ext_gcd(ll A, ll B, ll *X, ll *Y) {
    ll x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1;
    y2 = 0;
    x1 = 0;
    y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2;
    *Y = y2;
    return r2;
}
pair<ll, ll> chinese_remainder_theorem(vector<ll> A, vector<ll> M) {
    ll n = A.size();
    ll a1 = A[0];
    ll m1 = M[0];
    ll a2 = A[1];
    ll m2 = M[1];
    ll g = __gcd(m1, m2);
    if (a1 % g != a2 % g) return {9e18, 9e18};
    ll p, q;
    ext_gcd(m1 / g, m2 / g, &p, &q);
    ll mod = m1 / g * m2;
    ll x = ((__int128)a1 * (m2 / g) % mod * q % mod + (__int128)a2 * (m1 / g) % mod * p % mod) % mod;
    a1 = x;
    if (a1 < 0) a1 += mod;
    m1 = mod;
    return {a1, m1};
}

void solve() {
    ll n, m, d, x, y;
    cin >> n >> m >> d >> x >> y;
    ll ans = 0;
    ll add = min(n * y, m * x);
    if (1) {
        vl A = {0, 0};
        vl M = {2 * n * y, 2 * m * x};
        pll p = chinese_remainder_theorem(A, M);
        ans = p.second;
    }
    if (1) {
        vl A = {d * y, 0};
        vl M = {2 * n * y, 2 * m * x};
        pll p = chinese_remainder_theorem(A, M);
        ans = min(ans, p.first + add);
    }
    if (1) {
        vl A = {d * y, m * x};
        vl M = {2 * n * y, 2 * m * x};
        pll p = chinese_remainder_theorem(A, M);
        ans = min(ans, p.first + add);
    }
    if (1) {
        vl A = {(n + d) * y, 0};
        vl M = {2 * n * y, 2 * m * x};
        pll p = chinese_remainder_theorem(A, M);
        if (p.first != 0) {
            ans = min(ans, p.first + add);
        }
    }
    if (1) {
        vl A = {(n + d) * y, m * x};
        vl M = {2 * n * y, 2 * m * x};
        pll p = chinese_remainder_theorem(A, M);
        ans = min(ans, p.first + add);
    }
    cout << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}