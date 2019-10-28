ll mulmod (ll a, ll b, ll c) { // (a*b)%c evitando overflow, O(log b)
	ll x = 0, y = a%c;
	while (b){
		if (b&1) x = (x+y) % c;
		y = (y<<1) % c;
		b>>=1;
	}
	return x % c;
}

ll expmod (ll b, ll e, ll m){ // O(log e)
	if(!e) return 1;
	ll q= expmod(b,e>>1,m); q=mulmod(q,q,m);
	return (e&1)? mulmod(b,q,m) : q;
}

bool es_primo_prob (ll n, int a) {
	if (n == a) return true;
	ll s = 0,d = n-1;
	while (!(d&1)) s++,d>>=1;
	
	ll x = expmod(a,d,n);
	if ((x == 1) || (x+1 == n)) return true;
	
	for (int i=0; i < s-1; i++){
		x = mulmod(x, x, n);
		if (x == 1) return false;
		if (x+1 == n) return true;
	}
	return false;
}
		
bool rabin (ll n){ //devuelve true si n es primo
	if (n == 1)	return false;
	const int ar[] = {2,7,61}; //32 bits
	const int ar[] = {2,3,5,7,11,13,17,19,23,29,31,37}; // 64 bits
	for (int i = 0; i < 9; i++)
		if (!es_primo_prob(n,ar[i]))
			return false;
	return true;
}

ll rho(ll n){
    if( (n & 1) == 0 ) return 2;
    ll x = 2 , y = 2 , d = 1;
    ll c = rand() % n + 1;
    while( d == 1 ){
        x = (mulmod( x , x , n ) + c)%n;
        y = (mulmod( y , y , n ) + c)%n;
        y = (mulmod( y , y , n ) + c)%n;
        if( x - y >= 0 ) d = gcd( x - y , n );
        else d = gcd( y - x , n );
    }
    return d==n? rho(n):d;
}

map<ll,ll> prim; 
void factRho (ll n){ //O (lg n)^3. un solo numero
	if (n == 1) return;
	if (rabin(n)){
		prim[n]++;
		return;
	}
	ll factor = rho(n);
	factRho(factor);
	factRho(n/factor);
}
