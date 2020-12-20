const ll maxn=(1<<21)+5;
void ntt(ll *a,ll n,ll g,ll mod){
    for(ll i=0,j=0;i<n;i++) {
        if(i<j) swap(a[i],a[j]);
        ll bit=n>>1;
        for(;j&bit;bit>>=1) j^=bit;
        j^=bit;
    }
    rep(i,0,n) a[i]%=mod;
    for(ll len=1;2*len<=n;len*=2){
        ll wlen=binpow(g,(mod-1)/(2*len),mod);
        for(ll i=0;i+2*len<=n;i+=2*len){
            for(ll j=0,wi=1;j<len;j++,wi=wi*wlen%mod){
                ll u=a[i|j],v=wi*a[i|len|j]%mod;
                a[i|j]=u+v<mod?u+v:u+v-mod, a[i|len|j]=u-v<0?u-v+mod:u-v;
            }
        }
    }
}
void conv(ll *a, ll *b, ll n, ll g, ll mod){
    ntt(a,n,g,mod);
    ntt(b,n,g,mod);
    rep(i,0,n) a[i]=a[i]*b[i]%mod;
    ntt(a,n,inv(g,mod),mod);
    rep(i,0,n) a[i]=a[i]*inv(n,mod)%mod;
}
ll garner(ll *a, ll *m, ll (&inv)[3][3], ll mod){
    rep(i,0,3) rep(j,0,i) a[i]=(a[i]-a[j]+m[i])*inv[j][i]%m[i];
    per(i,0,2) a[i]=(a[i]+a[i+1]*m[i])%mod;
    return a[0];
}
void conv_mod(ll *a, ll *b, ll an, ll bn, ll mod){
    static ll x[maxn], y[maxn], ans[maxn][3],minv[3][3];
    static ll m[]={(5<<25)+1,(7<<26)+1,(119<<23)+1};
    rep(i,0,3) rep(j,0,3) minv[i][j]=inv(m[i],m[j]);
    ll n=1ll<<64-__builtin_clzll(an+bn-1);
    rep(i,0,3) {
        copy(a,a+n,x), copy(b,b+n,y);
        conv(x,y,n,3,m[i]);
        rep(j,0,n) ans[j][i]=x[j];
    }
    rep(i,0,n) a[i]=garner(ans[i],m,minv,mod);
}
