vector<int> nxt, prv;
void list_init(int n) {
        nxt.clear(); nxt.assign(n+1,n);
        prv.clear(); prv.assign(n+1,n);
}
void list_erase(int node) {
    nxt[prv[node]] = nxt[node];
    prv[nxt[node]] = prv[node];
}
