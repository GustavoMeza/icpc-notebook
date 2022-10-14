// indexado en 1
// solo 1 componente conexa
// id es el bloque al que pertenece
// p es el padre en el block-cut tree
struct Tarjan {
        Graph g;
        vector<ll> num, low, stk, id, p;
        ll t=0;
        void dfs(ll x, ll w) {
                t++;
                num[x] = low[x] = t;
                stk.push_back(x);
                for(ll y: g[x]) {
                        if(!num[y]) {
                                dfs(y,x);
                                low[x] = min(low[x], low[y]);
                                if(low[y] >= num[x]) {
                                        ll ncc = p.size(), z=0;
                                        id[x] = x;
                                        p.push_back(x);
                                        while(z != y) {
                                                z = stk.back();
                                                stk.pop_back();
                                                if(!id[z]) id[z] = ncc;
                                                else p[z] = ncc;
                                        }
                                }
                        } else if(y!=w) {
                                low[x] = min(low[x], num[y]);
                        }
                }
        }
        Tarjan(Graph &g) : g(g), num(g.size()), low(g.size()), id(g.size()), p(g.size()) {
                dfs(1,0);
                if(count(all(p),1) == 1) {
                        ll x = find(all(p), 1) - begin(p);
                        id[1] = x;
                        p[x] = 0;
                }
        }
};
