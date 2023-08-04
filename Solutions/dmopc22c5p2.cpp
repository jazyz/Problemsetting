#include <bits/stdc++.h>
#include <fstream>
using namespace std;

// #define int long long

bool DEBUG = 1;
#define deb(x) if(DEBUG) cout<<#x<<" " <<x<<"\n";

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ppi pair<pii,int>
#define pip pair<int,pii>
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
#define loop(i,s,e) for(int i = s; i <= e; i++)
#define loopd(i,s,e) for(int i = s; i >= e; i--)
#define nl "\n"
#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
#define popcount __builtin_popcountll
#define log2(x) ((x==0)? 0:63 - __builtin_clzll(x))

inline ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}
inline ll lcm(ll a, ll b) { return (a / gcd(a, b))*b;}

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
Invariants, SQRT Shenanigans,Binary Search, Surprise Graph
DP: Range DP, recursive
Characteristics of the optimal solution
Recall - Specific to General - Guess - Think like a problem - Pick a Method - Google - Print Out and Look

IMPORTANT:
AVOID SUNK COST FALLACY
IDEA SHEET - SAMPLES AND EXAMPLES - GO SLOW - DONT TUNNEL VISION - DONT SPAM SUB
DONT GUESS THINK MORE
ONLY SUB WHEN CERTAIN 
GO SLOW WRITE STUFF DOWN
*/
// ---------- TEMPLATE ----------

struct edge{
    ll x,y;
    bool operator<(const edge &o)const{
        if(x==o.x) return y<o.y;
        return x<o.x;
    }
};

const int MOD = 1e9+7;
// WRONG MOD??? 998244353
const int MAX = 2e5 + 5;
// CHECK MAX!!!

int a[MAX];

void solve() {
    int n;cin>>n;
    int l=1,r=n;
    if(n%2==1){
        l=2,r=n+1;
    }
    loop(i,l,r){
        if(i%4==1){
            a[i]=0;
        }else if(i%4==2){
            a[i]=-a[i-2]-1;
        }else if(i%4==3){
            a[i]=-1;
        }else{
            a[i]=-(a[i-1]+a[i-2]);
        }
    }
    loop(i,l,r){
        cout<<" ";
        cout<<a[i];
    }
    cout<<nl;
}      

signed main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int T=1;
	// cin>>T;
    while (T--) {
        solve();
    }
    return 0;
}