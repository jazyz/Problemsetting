#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int> 
#define vvi vector<vector<int>>
#define all(v) v.begin(), v.end()
#define loop(i,s,e) for(int i = s; i <= e; i++)
#define loopd(i,s,e) for(int i = s; i >= e; i--)
#define nl "\n"

const int BITS = 30;
void solve() {
    int n;
    cin>>n;
    vi a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i]; 
        assert(a[i]>=0&&a[i]<(1<<30));
    }
    int ans=0;
    vi b(BITS);
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            continue;
        }
        int x=63 - __builtin_clzll(a[i]);
        if(b[x]==1){
            ans++;
            fill(all(b),-1);
        }else{
            b[x]=1;
            for(int j=0;j<x;j++){
                if(b[j]!=-1 && ((1<<j)&a[i])){
                    b[j]^=1;
                }
            }
        }           
    }
    cout<<ans<<nl;
}      

signed main() {
    cin.sync_with_stdio(0);
    solve();
    return 0;
}