// FFFFFFTTTTTTT
// regresa el ultimo F y el primer T
// asume que f(lo) = F y f(hi) = T, nunca evalua en estos puntos.
// usar valores imposibles para lo y hi
tuple<int, int> bsearch(int lo, int hi, bool f(int)) {
    while(hi-lo>1) {
        int mid = lo + (hi-lo)/2;
        if(f(mid)) hi = mid;
        else lo = mid;
    }
    return make_tuple(lo, hi);
}
