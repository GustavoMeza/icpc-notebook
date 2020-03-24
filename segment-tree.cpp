struct stnode {}; // Datos que va a contener
stnode eye; // Elemento identidad
stnode combine(stnode a, stnode b) {} //Funcion que combina nodos

ll m; stnode st[2*maxn];
void build(ll x) { m=x; }
void update(ll p, stnode x) {
    st[p+=m]=x;
    while(p/=2) st[p]=combine(st[p*2],st[p*2+1]);
}
stnode query(ll l, ll r) {
    stnode ansl=eye, ansr=eye;
    for(l+=m,r+=m; l<r; l/=2,r/=2) {
        if(l&1) ansl=combine(ansl, st[l++]);
        if(r&1) ansr=combine(st[--r], ansr);
    }
    return combine(ansl, ansr);
}
