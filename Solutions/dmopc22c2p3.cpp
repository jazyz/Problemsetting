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
#define pq priority_queue
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

void pr(vi& a, int n) {
    loop(i, 1, n) {
        cout << a[i] << " ";
    }
    cout << nl;
}

const int MN = 5e5 + 5;

bool isPrime[MN];
vector<int> d[MN];

void precalc() {
    fill(isPrime + 2, isPrime + MN, true);
    for (int i = 2; i < MN; i++) {
        if (isPrime[i]) {
            d[i].push_back(i);
            for (int j = i + i; j < MN; j += i) {
                isPrime[j] = false;
                d[j].push_back(i);
            }
        }
    }
}

int deg[MN];
vi g[MN];
vi e[MN];

void solve() {
    do {
        int n;
        cin >> n;
        vi a(n + 1);
        loop(i, 1, n) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int div : d[a[i]]) {
                e[div].pb(i);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < (int)e[i].size() - 1; j++) {
                int u = e[i][j], v = e[i][j + 1];
                g[u].pb(v);
                deg[v]++;
            }
        }
        priority_queue<pii> q;
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 0) {
                q.push(mp(a[i], i));
            }
        }
        vi ans;
        while (!q.empty()) {
            pii p = q.top();
            int cur = p.S;
            q.pop();
            ans.pb(a[cur]);
            for (int b : g[cur]) {
                deg[b]--;
                if (!deg[b]) {
                    q.push(mp(a[b], b));
                }
            }
        }

        for (int x : ans) {
            cout << x << " ";
        }
        cout << nl;
    } while (0);
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    precalc();
    solve();
    return 0;
}