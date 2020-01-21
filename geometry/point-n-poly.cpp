// dos segmentos (a,b), (u,v) se intersectan?
bool segment_intersect(point a, point b, point u, point v) {
    auto dir_u = turn(u-a, b-a);
    auto dir_v = turn(v-a, b-a);
    auto dir_a = turn(a-u, v-u);
    auto dir_b = turn(b-u, v-u);
    return dir_u != dir_v && dir_u != COL && dir_v != COL
        && dir_a != dir_b && dir_a != COL && dir_b != COL;
}

// el punto a está dentro o fuera de p?
bool point_n_poly(poly p, point a) {
    point b(MAX_X, a.y);
    int j = size(p)-1;
    bool ans = false;
    for(int i = 0; i < size(p); i++) {
        if(segment_intersect(a, b, p[i], p[j])) {
            b=!b;
        }
        j = i;
    }
    return ans;
}
