// dependencies from utilities.cpp
// poly, cross

double area(poly p){
    double area = 0.0;
    int j = p.size()-1;
    for (int i=0;i<p.size();i++){
        area += cross(p[j], p[i]);
        j = i;
    }
    return area/2.0;
}
