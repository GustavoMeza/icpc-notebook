// Requires suffix-array

int p[MAXN*2],d[MAXN*2],str[MAXN*2],sz; set<int> ady[MAXN*2];
int new_node(int myp, int myd, int mystr){
    ady[myp].insert(sz);
    p[sz]=myp; d[sz]=myd; str[sz]=mystr;
    ady[sz].clear();
    return sz++;
}
void build_tree(){
    sz=0; new_node(0,0,0);
    int v=new_node(0,1,N+1);
    rep(i,1,N+1) {
        int lca=lcp(SA[i],SA[i-1]);
        while(lca<=d[p[v]]&&v) v=p[v];
        if(lca<d[v]) {
            int aux=new_node(p[v],lca,str[v]-d[v]+lca);
            ady[p[v]].erase(v);
            p[v]=aux;
            ady[aux].insert(v);
            v=p[v];
        }
        v=new_node(v,N+1-SA[i],N+1);
    }
}
