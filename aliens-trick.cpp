#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
using ll=long long;
const int MAXN=2e5+5; const ll inf=1e6;
struct edge {
    int u,v,w,s;
    bool operator <(edge rhs) {
        return w!=rhs.w?(w<rhs.w):(s>rhs.s);
    }
};
int p[MAXN],N; vector<edge> E;
int find(int x) { return p[x]==x?x:p[x]=find(p[x]); }
tuple<ll,int> solve(int lambda) {
    for(edge &e : E) if(e.s) e.w+=lambda;
    rep(i,1,N+1) p[i]=i;
    sort(E.begin(),E.end());
    ll cost=0; int count=0; 
    for(edge e: E) if(find(e.u)!=find(e.v)) {
        p[p[e.u]]=p[e.v];
        if(e.s) count++;
        cost+=e.w;
    }
    for(edge &e : E) if(e.s) e.w-=lambda;
    return {cost,count};
}
int M,K,W,u,v,w,s[MAXN];
bool sol_exists(){
    auto [cost_max,count_max]=solve(-inf); // use as many colored edges as possible
    auto [cost_min,count_min]=solve(inf); // use as little colored edges as possible
    int conn=1; rep(i,1,N+1) if(find(i)!=find(1)) conn=0;
    return count_min<=W && W<=count_max && conn;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>N>>M>>K>>W;
    rep(i,0,K) {cin>>u; s[u]=1; }
    rep(i,0,M) {cin>>u>>v>>w; E.push_back({u,v,w,s[u]+s[v]==1}); }
    if(!sol_exists()) { cout<<"-1\n"; exit(0); }
    ll lo=-inf,hi=inf;
    while(hi-lo>1){
        ll mid=(lo+hi)/2;
        auto [cost, count]=solve(mid);
        if(count<W) hi=mid; // if used few edges, make them cheaper
        else lo=mid;
    }
    auto [cost,count]=solve(lo);
    cout<<cost-W*lo<<"\n";
}
