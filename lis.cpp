#include <vector>

int LIS(vector<int> a){
    vector<int> Lis;
    Lis.push_back(a[0]);
    for (int i=1;i<a.size();i++){
        int voy = 0;
        int aum = Lis.size();
        while (aum)
            if (voy+aum<Lis.size() && Lis[voy+aum]<a[i]) voy+=aum;
            else aum/=2;
        if (voy==0 && a[i]<Lis[voy]) Lis[voy]=a[i];
        else if (a[i]<Lis[voy+1]) Lis[voy+1]=a[i];
        else if (voy+1==Lis.size() && a[i]>Lis[voy]) Lis.push_back(a[i]);
    }
    return Lis.size();
}

int LIS_PATH(vector<int> a){
    vector<int> Lis;
    vector<int> Ind;
    vector<int> Path;
    Ind.push_back(0);
    Path.push_back(-1);
    Lis.push_back(a[0]);
    for (int i=1;i<a.size();i++){
        int voy = 0;
        int aum = Lis.size();
        while (aum)
            if (voy+aum<Lis.size() && Lis[voy+aum]<a[i]) voy+=aum;
            else aum/=2;
        if (voy==0 && a[i]<Lis[voy]){
            Ind[voy]=i;
            Lis[voy]=a[i];
            Path.push_back(-1);
        }
        else if (voy+1==Lis.size() && a[i]>Lis[voy]){
            Ind.push_back(i);
            Lis.push_back(a[i]);
            Path.push_back(Ind[Ind.size()-2]);
        }
        else if (a[i]<Lis[voy+1]){
            Ind[voy+1]=i;
            Lis[voy+1]=a[i];
            Path.push_back(Ind[voy]);
        }
    }
    int x = Ind[Ind.size()-1];
    while (x!=-1){
        cout<<a[x]<<" ";
        x=Path[x];
    }
    return Lis.size();
}
