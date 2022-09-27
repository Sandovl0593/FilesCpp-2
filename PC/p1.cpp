#include <bits/stdc++.h>
using namespace std;

class Polinomio {
    int grado;
    vector<int> coef;
public:
    Polinomio() {}
    Polinomio(int grado_): grado(grado_) {
        coef.resize(grado+1);
        for (int i=0; i<grado+1; i++) {
            int num_al = rand()% 20;
            int pos = (rand()%1)?num_al:(num_al-2*num_al);
            coef.push_back(pos);
        }
    }

    void modificacion(int index, int value) { coef[index] = value; }

    friend ostream& operator<<(ostream& os, Polinomio pol) {
        for (int i=pol.coef.size()-1; i>=0; i--) {
            os << ((pol.coef[i]>=0)?" + ":" - ")<< abs(pol.coef[i]) << ((i>0)?((i==1)?"x":"x"+to_string(i)):"");
        } return os;
    }

    friend Polinomio operator+(Polinomio pol1, Polinomio pol2) {
        int j=0, suma= 0;
        Polinomio result((pol1.grado>pol2.grado)?pol1.grado:pol2.grado);
        for (int i=0; i<pol1.coef.size(); i--){
            result.modificacion(j++, pol1.coef[i] + pol2.coef[j]);
        } return result;
    }
};