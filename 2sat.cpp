// requires strongly-connected-components.cpp
// n predicates X_0, X_1, ... , X_n-1
// node i*2 is True version of X_i
// node i*2+1 is False version of X_i

void or_clause(int p, int q) {
    ady[p^1].push_back(q);
    ady[q^1].push_back(p);
}

void xor_clause(int p, int q) {
    or_clause(p, q);
    or_clause(p^1, q^1);
}

void true_clause(int p) {
    or_clause(p, p);
}

bool sat() {
    scc_init();
    for(int i = 0; i < ady.size(); i++)
        if(!dfs_num[i])
            scc(i);
    for(int i = 0; i < ady.size(); i+=2)
        if(SCC[i] == SCC[i^1])
            return false;
    return true;
}

void sat_init(int n) {
    ady.clear();
    ady.assign(2*n, vi());
}

