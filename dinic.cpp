// N vertices, M aristas, F flujo maximo
// O(N^2 M) O(M F)
// O(M sqrt(N)) si es una red de capacidad unitaria
namespace dinic{
    const int maxn=1e5+5,maxm=5e5+5;
    struct edge{int to;ll cap;} e[maxm];
    int s,t,m,p[maxn],q[maxn],d[maxn],v[maxn],c;
    vector<int> ady[maxn];
    // void clear(int n){rep(i,0,n)ady[i].clear();m=0;}
    void add_edge(int from,int to,ll cap){
        ady[from].push_back(m); e[m++]={to,cap};
        ady[to].push_back(m); e[m++]={from,0};
    }
    bool bfs(){
        int f=0,g=1;
        q[0]=s,d[s]=0,v[s]=++c;
        while(f<g){
            int x=q[f++]; p[x]=0;
            for(int i:ady[x]) if(v[e[i].to]<c&&e[i].cap)
                q[g++]=e[i].to,d[e[i].to]=d[x]+1,v[e[i].to]=c;
        }
        return v[t]==c;
    }
    ll dfs(int x,ll neck){
        if(x==t) return neck;
        ll f=0;
        for(;p[x]<ady[x].size()&&f<neck;p[x]++){
            int i=ady[x][p[x]]; auto &[y,cap]=e[i];
            if(!cap||d[y]!=d[x]+1) continue;
            ll f0=dfs(y,min(neck-f,cap));
            cap-=f0,e[i^1].cap+=f0,f+=f0;
        }
        return f;
    }
    ll max_flow(int _s, int _t){
        ll flow=0;s=_s,t=_t;
        while(bfs()) flow+=dfs(s,inf);
        return flow;
    }
}}
