vi add(vi a, vi b, int base) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry=0;
    vi c;
    int l = max(a.size(), b.size());
    for(int i = 0; i<l; i++) {
        int s = (i<a.size()?a[i]:0)+(i<b.size()?b[i]:0)+carry;
        c.push_back(s%base);
        carry = s/base;
    }
    if(carry) c.push_back(carry);
    reverse(c.begin(), c.end());
    return c;
}

vi half(vi a, int base) {
    vi b;
    int carry = 0;
    for(int i = 0; i < a.size(); i++) {
        int s = base*carry+a[i];
        b.push_back(s/2);
        carry = s%2;
    }
    return b;
}
