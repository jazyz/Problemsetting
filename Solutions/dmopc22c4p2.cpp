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

void solve(){
    int n,m;cin>>n>>m;
    assert(n<=1500);
    assert(m<=1500);
    vvi A(n+1,vi(m+1));
    vvi T(n+1,vi(m+1));
    loop(i,1,n){
        loop(j,1,m){
            cin>>A[i][j];
            assert(A[i][j]<=1e9);
            assert(A[i][j]>=1);
        }
    }
    loop(i,1,n){
        loop(j,1,m){
            cin>>T[i][j];
            assert(T[i][j]<=1e9);
            assert(T[i][j]>=1);
        }
    }
    bool bad1=0;
    bool bad2=0;
    loop(i,1,n){
        loop(j,1,m){
            int a=T[i][j];
            int b=T[n-i+1][j];
            int c=T[i][m-j+1];
            int d=T[n-i+1][m-j+1];
            int a1=A[i][j];
            int b1=A[n-i+1][j];
            int c1=A[i][m-j+1];
            int d1=A[n-i+1][m-j+1];
            bool f=(i==n-i+1);
            bool g=(j==m-j+1);
            if(f&&g){
                if((a-a1)%2!=0){
                    bad1=1;bad2=1;
                }
            }else if(!f&&!g){
                if(a+d-a1-d1!=b-b1+c-c1){
                    bad1=1;
                }
                if(a+d-b1-c1!=b-a1+c-d1){
                    bad2=1;
                }
            }else if(f){
                if(((a+c-a1-c1)%2)!=0){
                    bad1=1;bad2=1;
                }
            }else{
                if(((a+b-a1-b1)%2)!=0){
                    bad1=1;bad2=1;
                }
            }
        }
    }
    if(!bad1||!bad2){
        cout<<"YES"<<nl;
    }else{
        cout<<"NO"<<nl;
    }
}

int main() {
    cin.sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}