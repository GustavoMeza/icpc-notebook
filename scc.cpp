namespace scc{
    const int maxn=5e2+5;
    int num[maxn],cc[maxn],s[maxn],v,NUM,ncc,sz[maxn];
    vector<int> ady[maxn]; unordered_set<int> dag[maxn];
    void clear(int n) {rep(i,0,n) num[i]=0,cc[i]=-1,ady[i].clear(); NUM=ncc=0;}
    int dfs(int x){
        int lo=num[x]=++NUM; s[v++]=x;
        for(int y:ady[x]) if(cc[y]<0) lo=min(lo,num[y]?:dfs(y));
        if(num[x]==lo) {
            // reduce la gráfica a una dag, x pertenece a cc[x], x colapsa sz[x] nodos
            cc[x]=ncc++,dag[cc[x]].clear(),sz[cc[x]]=0;
            for(int y=-1;y!=x;) {
                cc[y=s[--v]]=cc[x];
                sz[cc[x]]++;
                for(int z:ady[y]) if(cc[z]!=cc[x]) dag[cc[x]].insert(cc[z]);
            }
        }
        return lo;
    }
    void tarjan(int n){rep(i,0,n) if(cc[i]<0) dfs(i);}
}
