struct Func{ // f(x)= piecewise linear function {m,b,p} (x-c)
    ll m,b,c,mL;
    map<ll,ll> p;
};
void init(Func &f, ll c, ll d) { // f(x)=d*abs(x-c)
    f.m=d, f.b=0, f.c=c, f.mL=-d;
    f.p.clear(); f.p[0]=2*d;
}
void shift(Func &f, ll k) { // Move the function to right k spaces
    f.c+=k;
}
void set_c(Func &f, ll k) { // Doesn't changes function, only the representation
    map<ll,ll> p2;
    for(auto it: f.p) p2[it.first+f.c-k]=it.second;
    f.p=p2;
    f.b+=f.m*(k-f.c), f.c=k;
}
void add(Func &f, Func &g) { // f(x)=f(x)+g(x)
    set_c(g,f.c);
    f.m+=g.m, f.b+=g.b, f.mL+=g.mL;
    for(auto it: g.p) f.p[it.first]+=it.second;
}
void pop_back(Func &f, ll delta) { // remove delta change points from right
    while(delta) {
        ll x=f.p.rbegin()->first, d=f.p.rbegin()->second;
        ll k=min(d,delta);
        f.m-=k, f.b+=x*k;
        f.p[x]-=k;
        delta-=k;
        if(f.p[x]==0) f.p.erase(x);
    }
}
void pop_front(Func &f, ll delta) { // remove delta change points from left
    while(delta) {
        ll x=f.p.begin()->first, d=f.p.begin()->second;
        ll k=min(d,delta);
        f.mL+=k;
        f.p[x]-=k;
        delta-=k;
        if(f.p[x]==0) f.p.erase(x);
    }
}
tuple<ll,ll> crop(Func &f, ll d) { // remove slopes with |m|>d
    ll l=-inf,r=inf;
    if(d<f.m) {
        pop_back(f,f.m-d);
        r=f.p.rbegin()->first+f.c;
    }
    if(f.mL<-d) {
        pop_front(f,-d-f.mL);
        l=f.p.begin()->first+f.c;
    }
    return {l,r};
}
void print(Func f) {
    set_c(f,0);
    cout<<"m="<<f.m<<" b="<<f.b<<" p={";
    for(auto it: f.p) cout<<it.first<<":"<<it.second<<" ";
    cout<<"}\n";
}
