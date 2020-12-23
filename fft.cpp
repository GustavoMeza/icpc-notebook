namespace fft{
const int maxn=(1<<21)+5;
int a[maxn],b[maxn],r[maxn],w[maxn],mod,n,ninv;
void init(int _n,int g,int _mod){
    n=1<<32-__builtin_clz(_n),mod=_mod,ninv=inv(n,mod);
    rep(i,0,n) r[i]=r[i>>1]>>1|(i&1?n>>1:0); // reversal bit permutation
    int wn=binpow(g,(mod-1)/n,mod); w[n>>1]=1;
    rep(i,(n>>1)+1,n) w[i]=1ll*w[i-1]*wn%mod;
    per(i,1,n>>1) w[i]=w[i<<1];
}
void ntt(int *a){
    rep(i,0,n) if(i<r[i]) swap(a[i],a[r[i]]);
    for(int len=1;len<n;len<<=1) for(int i=0;i<n;i+=len<<1) rep(j,0,len){
        int u=a[i|j],v=1ll*w[len|j]*a[i|len|j]%mod;
        a[i|j]=u+v<mod?u+v:u+v-mod;
        a[i|len|j]=u-v<0?u-v+mod:u-v;
    }
}
void conv(){
    ntt(a); ntt(b);
    rep(i,0,n) a[i]=1ll*a[i]*b[i]%mod;
    reverse(a+1,a+n); ntt(a);
    rep(i,0,n) a[i]=1ll*a[i]*ninv%mod;
}
}
// Si a[i] sobrepasa el primo se necesita hacer fft con dos o tres primos distintos
namespace convmod{
int a[fft::maxn],b[fft::maxn],ans[fft::maxn][3];
const int m[]={(5<<25)+1,(7<<26)+1,(119<<23)+1},inv[]={104391568,715912618,554580198},g=3; // 3 es raiz primitiva de esos primos
int garner(int *a,int mod){
    rep(i,0,3) rep(j,0,i) a[i]=1ll*(a[i]-a[j]+m[i])*inv[i+j-1]%m[i]; // Los coeficientes del número en la mixed-radix de los primos
    per(i,0,2) a[i]=(a[i]+1ll*a[i+1]*m[i])%mod; // Evaluación
    return a[0];
}
void solve(int an, int bn, int mod){
    rep(i,0,3) {
        fft::init(an+bn-1,g,m[i]);
        rep(j,0,fft::n) fft::a[j]=j<an?a[j]%m[i]:0;
        rep(j,0,fft::n) fft::b[j]=j<bn?b[j]%m[i]:0;
        fft::conv();
        rep(j,0,fft::n) ans[j][i]=fft::a[j];
    }
    rep(i,0,fft::n) a[i]=garner(ans[i],mod);
}
}
