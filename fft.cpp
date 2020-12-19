const ll maxn=524288;
ll garner(ll *a, ll *m, ll n, ll mod){
    rep(i,0,n) rep(j,0,i) a[i]=(a[i]-a[j]%m[i]+m[i])*inv(m[j],m[i])%m[i];
    ll ans=a[n-1];
    per(i,0,n-1) ans=(a[i]+ans*m[i])%mod;
    return ans;
}
void ntt(ll *a,ll n,ll g,ll mod){
    for(ll i=0,j=0;i<n;i++) {
        if(i<j) swap(a[i],a[j]);
        ll bit=n>>1;
        for(;j&bit;bit>>=1) j^=bit;
        j^=bit;
    }
    for(ll len=2;len<=n;len<<=1){
        ll wlen=binpow(g,(mod-1)/len,mod);
        for(ll bat=0;bat+len<=n;bat+=len){
            for(ll i=bat,wi=1;i<bat+len/2;i++,wi=wi*wlen%mod){
                ll u=a[i],v=wi*a[i+len/2]%mod;
                a[i]=(u+v)%mod, a[i+len/2]=(u-v+mod)%mod;
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
void conv_mod(ll *a, ll *b, ll an, ll bn, ll mod){
    static ll x[maxn*4], y[maxn*4], ans[maxn*4][3];
    static ll m[]={(119<<23)+1,(5<<25)+1,(7<<26)+1};
    ll n=1ll<<64-__builtin_clzll(an+bn-1);
    rep(i,0,3) {
        copy(a,a+n,x), copy(b,b+n,y);
        conv(x,y,n,3,m[i]);
        rep(j,0,n) ans[j][i]=x[j];
    }
    rep(i,0,n) a[i]=garner(ans[i],m,3,mod);
}
