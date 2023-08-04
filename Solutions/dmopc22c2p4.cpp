#include <bits/stdc++.h>
#include <fstream>
using namespace std;

// #define int long long

#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define vi vector<int> 
#define vvi vector<vector<int>>
#define vpi vector<pii> 
#define vpl vector<pair<ll,ll>> 
#define pq priority_queue 
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
#define loop(i,s,e) for(int i = s; i <= e; i++)
#define loopd(i,s,e) for(int i = s; i >= e; i--)
#define nl "\n"
#define popcount __builtin_popcountll
#define log2(x) ((x==0)? 0:63 - __builtin_clzll(x))

inline ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}
inline ll lcm(ll a, ll b) { return (a / gcd(a, b))*b;}

const int N = 3e5 + 5;
const int MOD = 1e9+7;
// WRONG MOD??? 998244353
const int MAX = 3e5 + 5;
int fact[N], inv[N], invfact[N];
void factInverse() {
	fact[0] = inv[1] = fact[1] = invfact[0] = invfact[1] = 1;
	for (long long i = 2; i < N; i++) {
		fact[i] = (1LL*fact[i - 1] * i) % MOD;
		inv[i] = MOD - (1LL*inv[MOD % i] * (MOD / i) % MOD);
		invfact[i] = (1LL*inv[i] * invfact[i - 1]) % MOD;
	}
}
 
int mul(int x, int y) {
	return (1LL * x * y) % MOD;
}
 
int fpow(int a, int b){
    if (b == 0) return 1;
    ll res = fpow(a, b / 2);
    if (b % 2) return ((res * res)%MOD * a)%MOD;
    else return (res * res)%MOD;
}

int modinv(int a){
	return fpow(a,MOD-2);
}

vector<int> g[MAX];
int color[MAX];
int sz[MAX]; // subtrees
int dp[MAX]; // orders
int n,k;

void init(int cur, int pre, vi&cnt, vi&ways, vi&totsz){
    int c=color[cur];
    dp[cur]=1;sz[cur]=1;cnt[c]++;
    for(int b:g[cur]){
        if(b==pre){
            continue;
        }
        init(b,cur,cnt,ways,totsz);
        dp[cur]=1LL*dp[cur]*invfact[sz[b]]%MOD*dp[b]%MOD;
        sz[cur]+=sz[b];
    }
    dp[cur]=mul(dp[cur],fact[sz[cur]-1]);
    if(cnt[c]==1){
        ways[c]=1LL*ways[c]*dp[cur]%MOD*invfact[sz[cur]]%MOD;
        totsz[c]+=sz[cur];
    }
    cnt[c]--;
}
void dfs(int cur, int pre, int lastdp, vi&lastroot, vi&ways, vi&totsz, vpl&best){
    int root=lastroot[color[cur]];
    ways[root]=1LL*ways[root]*dp[cur]%MOD*invfact[sz[cur]]%MOD;
    totsz[root]+=sz[cur];    
    for(int b:g[cur]){
        if(b==pre){
            continue;
        }
        lastroot[color[cur]]=b;
        int newdp=1LL*lastdp*sz[b]%MOD*fact[n-sz[b]-1]%MOD*invfact[n-sz[b]]%MOD;
        int curdp=1LL*lastdp*modinv(dp[b])%MOD*invfact[n-1]%MOD*fact[sz[b]]%MOD*fact[n-sz[b]-1]%MOD;
        totsz[b]+=n-sz[b];
        ways[b]=1LL*ways[b]*curdp%MOD*invfact[n-sz[b]]%MOD;
        dfs(b,cur,newdp,lastroot,ways,totsz,best);
        lastroot[color[cur]]=root;
    }
    ways[cur]=mul(ways[cur],fact[totsz[cur]]);
    int c=color[pre];
    if(totsz[cur]<best[c].F){
        best[c]={totsz[cur],ways[cur]};
    }else if(totsz[cur]==best[c].F){
        best[c].S+=ways[cur];
    }
}
void solve(){
    factInverse();
    cin>>n>>k;
    loop(i,1,n){
        cin>>color[i];
    }
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vi cnt(n+1),ways(n+1),totsz(n+1);
    vpl best(k+1);
    fill(all(best),mp(n-1,0));
    fill(all(ways),1);
    init(1,0,cnt,ways,totsz);
    loop(i,1,k){
        ways[i]=mul(ways[i],fact[totsz[i]]);
        if(totsz[i]!=0&&totsz[i]<best[i].F){
            best[i]={totsz[i],ways[i]};
        } else if(totsz[i]==best[i].F){ 
            best[i].S+=ways[i];
        }
    }
    fill(all(ways),1);
    fill(all(totsz),0);
    vi lastroot(n+1);
    dfs(1,0,dp[1],lastroot,ways,totsz,best);
    loop(i,1,k){
        best[i].S%=MOD;
        if(best[i].S<0){
            best[i].S+=MOD;
        }
        cout<<best[i].S<<nl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}