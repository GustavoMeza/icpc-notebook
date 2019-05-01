// dependencies from utilities.cpp
// point, vec, poly

double area(poly p){
    double area = 0.0;
    int j = p.size()-1;
    for (int i=0;i<p.size();i++){
        area += (p[j].x + p[i].x) * (p[j].y - p[i].y);
        j = i;
    }
    return area/2.0;
}
