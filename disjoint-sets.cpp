ll p[maxn];
ll init() { iota(p, p+maxn, 0); }
ll parent(ll x) { return p[x]==x?x:p[x]=parent(p[x]); }
ll disjoint(ll x, ll y) { return parent(x)!=parent(y); }
void unite(ll x, ll y) { if(disjoint(x,y)) p[p[x]]=p[y]; }
