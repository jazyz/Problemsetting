#include <bits/stdc++.h>
#include <fstream>
using namespace std;

#define ll long long
#define vi vector<int> 
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define all(v) v.begin(), v.end()
#define loop(i,s,e) for(int i = s; i <= e; i++)
#define loopd(i,s,e) for(int i = s; i >= e; i--)
#define nl "\n"

const int MAX = 1e6 + 5;

void solve(){
    int n,q;cin>>n>>q;
    vi p(n+1);
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    vi cc(n+1);
    int cnt=0;
    loop(i,1,n){
        if(!cc[i]){
            int j=i;cnt++;
            do{
                cc[j]=i;j=p[j];
            }while(j!=i);
        }
    }
    vi setv(n+1);
    vi setc(n+1);
    while(q--){
        int k;cin>>k;   
        vi v(k);
        for(int i=0;i<k;i++){
            cin>>v[i];
            setv[v[i]]=1;
        }
        int ans=cnt;
        for(int i=0;i<k;i++){
            int x=cc[v[i]];
            if(setc[x]==0){
                ans--;
            }
            setc[x]=1;
            if(setv[p[v[i]]]==0){
                ans++;
            }
        }
        for(int i=0;i<k;i++){
            setv[v[i]]=0;
            setc[cc[v[i]]]=0;
        }
        cout<<ans<<nl;
        assert(ans>=1&&ans<=n);
    }   
    // assert(sums>=1e6-2);
}

int main() {
    cin.sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}