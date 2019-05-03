//pi[i] = longitud del prefijo propio mas grande de s[0..i] que tambien es sufijo
vi prefix_function(string s) {
    vi pi(s.size());
    for(int i=1,j=0; i<s.size(); i++) {
        while(j && s[i]!=s[j]) j=pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

// Busca las coincidencias de p en s, regresa indices de inicio
vi kmp(string s, string p) {
    vi pi = prefix_function(p);
    vi ans;
    for(int i=0,j=0; i<s.size(); i++) {
        while(j && s[i]!=p[j]) j=pi[j-1];
        if(s[i]==p[j]) j++;
        if(j==p.size()) {
            ans.push_back(i-j+1);
            j=pi[j-1];
        }
    }
    return ans;
}
