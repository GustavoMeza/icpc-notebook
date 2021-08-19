// add to range, assign to range, get range sum
enum OpType { add, set };
struct Op{ OpType type; ll val; };
Op eye={OpType::add,0};
Op combine(Op a, Op b) { // a_time < b_time
    if(b.type==OpType::set) return b;
    return {a.type, a.val+b.val};
}
ll apply(Op op, ll prev, int l, int r) {
    return op.type==OpType::add ? prev+op.val*(r-l) : op.val*(r-l); 
}
const int N=1<<18; ll st[N*2]; Op lazy[N*2];
void prop(int L, int R, int p, int l, int r) {
    st[p]=apply(lazy[p],st[p],l,r);
    if(p<N) {
        lazy[2*p]=combine(lazy[2*p],lazy[p]);
        lazy[2*p+1]=combine(lazy[2*p+1],lazy[p]);
    }
    lazy[p]=eye;
    if(L<=l&&r<=R||r<=L||R<=l) return;
    int m=(l+r)/2;
    prop(L,R,2*p,l,m);
    prop(L,R,2*p+1,m,r);
    st[p]=st[p*2]+st[p*2+1];
}
void update(int L, int R, Op op){
    prop(L,R,1,0,N);
    for(int l=L+N,r=R+N;l<r;l/=2,r/=2) {
        if(l&1) lazy[l++]=op;
        if(r&1) lazy[--r]=op;
    }
    prop(L,R,1,0,N);
}
ll query(int l, int r) {
    prop(l,r,1,0,N);
    ll ans=0;
    for(l+=N,r+=N;l<r;l/=2,r/=2) {
        if(l&1) ans+=st[l++];
        if(r&1) ans+=st[--r];
    }
    return ans;
}
void build(int n, int *A) {
    rep(i,0,n) st[i+N]=A[i];
    per(i,1,N) st[i]=st[i*2]+st[i*2+1];
    rep(i,1,2*N) lazy[i]=eye;
}
