#include <vector>

vector<int> LIS(vector<int> a){
    vector<int> Lis;
    Lis.push_back(a[0]);
    for (int i=1;i<a.size();i++){
        voy=0;
        aum=Lis.size();
        while (aum)
            if (voy+aum<Lis.size() && Lis[voy+aum]<a[i]) voy+=aum;
            else aum/=2;
        if (voy+1==Lis.size() && a[i]>Lis[voy]) Lis.push_back(a[i]);
        else Lis[voy+1]=min(a[i],Lis[voy+1]);
    }
    return Lis;
}
