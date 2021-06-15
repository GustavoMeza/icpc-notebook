#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

//SOLUCIONA UNA DP DEL ESTILO DP(i,j)=min{dp(i-1, k-1)+C(k, j) | 1<=k<=j  }; i<=N, j<=M
namespace DnC {

    vector<long long> renglonAnt;
    vector<long long> renglonCur;
    //IMPLEMENTA ESTO
    long long inline C(int i, int j) {
        throw "NO IMPLEMENTADO";


    }
    void _computeRow(int l, int r, int lop, int rop) {
        if (l > r)return;
        int mid = (l+r)/2;

        //SOLVE FOR DP(__,mid) con el ciclo;
        long long best=1e18;   //CAMBIA ESTO A NEGATIVO PARA DP DE MAXIMOS
        int pos;
        for (int k=lop; k<= rop && k<=mid; k++) {
            if (best > renglonAnt[k-1]+C(k, mid) ) {  //CAMBIA EL SIGNO PARA DP DE MAXIMOS
                best=renglonAnt[k-1]+C(k, mid);
                pos=k;
            }
        }

        renglonCur[mid]=best;
        _computeRow(l, mid-1, lop, pos);
        _computeRow(mid+1,r, pos, rop);

    }
    //CALL THIS FOR SOLUTION
    long long respuesta(int N, int M) {
        renglonAnt.resize(M+5);
        renglonCur.resize(M+5);
        for (int i=0; i < M; i++) {
            renglonAnt[i]=C(0, i);
        }

        for (int i=1; i < N; i++) {
            _computeRow(0, M-1, 0, M-1);
            renglonAnt.swap(renglonCur);
        }
        return renglonAnt[M-1];
    }
}
int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    DnC::C(0,0);

    return 0;
}
