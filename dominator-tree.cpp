const int N = 1e5+10;
const int M = 5e5+10;
vi g[N];
vi tree[N],rg[N],bucket[N];
int sdom[N],par[N],dom[N],dsu[N],label[N];
int arr[N],rev[N],T;
int Find(int u,int x=0) {
	if(u==dsu[u])return x?-1:u;
	int v = Find(dsu[u],x+1);
	if(v<0)return u;
	if(sdom[label[dsu[u]]] < sdom[label[u]])
		label[u] = label[dsu[u]];
	dsu[u] = v;
	return x?v:label[u];
}
void Union(int u,int v) { dsu[v]=u; }
void dfs0(int u) {
	T++;arr[u]=T;rev[T]=u;
	label[T]=T;sdom[T]=T;dsu[T]=T;
	for(int w:g[u]) {
		if(!arr[w])dfs0(w),par[arr[w]]=arr[u];
		rg[arr[w]].PB(arr[u]);
	}
}
void build_dominator(int r) {
  dfs0(r);
	int n=T;
	per(i,1,n+1) {
		for(int j:rg[i]) sdom[i] = min(sdom[i],sdom[Find(j)]);
		if(i>1) bucket[sdom[i]].PB(i);
		for(int w:bucket[i])
		{
			int v = Find(w);
			if(sdom[v]==sdom[w])dom[w]=sdom[w];
			else dom[w] = v;
		}
		if(i>1) Union(par[i],i);
	}
	for(int i=2;i<=n;i++)
	{
		if(dom[i]!=sdom[i]) dom[i]=dom[dom[i]];
		tree[rev[i]].PB(rev[dom[i]]);
		tree[rev[dom[i]]].PB(rev[i]);
	}
}
