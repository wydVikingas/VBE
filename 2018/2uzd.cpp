#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct Slidininkas{
    char v[21];
    int laikas;
};

void skaityti(Slidininkas S[], Slidininkas F[], int &n, int &m) {
    ifstream fin("U2.txt");
    if (!fin) {
        cerr << "Could not open U2.txt\n";
        exit(1);
    }
    int val, min, sec;

    fin >> n;
    for (int i = 0; i < n; i++){
        fin.get(S[i].v, 21);
        fin >> val >> min >> sec;
        S[i].laikas = val*3600 + min*60 + sec;
    }
    fin >> m;
    for (int i = 0; i < m; i++) {
        fin.get(F[i].v, 21);
        fin >> val >> min >> sec;
        for(int j = 0; j < n; j++) {
            if(strcmp(F[i].v, S[j].v) == 0) {
                F[i].laikas = val*3600+min*60+sec - S[j].laikas;
            }
        }
    }
    fin.close();
}

void Rikiuoti(Slidininkas F[], int m){
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m - 1; j++) {
            if((F[j].laikas > F[j+1].laikas) || (F[j].laikas == F[j+1].laikas && strcmp(F[j].v, F[j+1].v) > 0)){
                swap(F[j], F[j+1]);
            }
        }
    }
}

void rasyti(Slidininkas F[], int m) {
    ofstream fout("U2rez.txt");
    for (int i = 0; i < m; i++) {
        fout << F[i].v << " " << F[i].laikas / 60 << " " << F[i].laikas % 60 << endl;
    }
    fout.close();
}

int main() {
    Slidininkas S[30], F[30];
    int n, m;
    skaityti(S, F, n, m);
    Rikiuoti(F, m);
    rasyti(F, m);
    return 0;
}
