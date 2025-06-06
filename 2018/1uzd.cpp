#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void skaityti(int &R, int &G, int &Z) {
    ifstream fin("U1.txt");
    int n, kiekis;
    string spalva;
    fin >> n;
    for (int i = 0; i < n; i += 1) {
        fin >> spalva >> kiekis;
        if (spalva == "G"){
            G+=kiekis;
        }
        else if (spalva == "R"){
            R+=kiekis;
        }
        else {
            Z+=kiekis;
        }
    }

    fin.close();
}

int skaiciuoti(int R, int G, int Z) {
    return min(min(R/2,G/2),Z/2);
}

void spausdinti(int R, int G, int Z) {
    ofstream fout("U1rez.txt");
    fout << skaiciuoti(R,G,Z) << endl;
    fout << "G = " << G-skaiciuoti(R,G,Z) * 2 << endl;
    fout << "Z = " << Z-skaiciuoti(R,G,Z) * 2 << endl;
    fout << "R = " << R-skaiciuoti(R,G,Z) * 2 << endl;

    fout.close();
}

int main() {
    int R = 0, G = 0, Z = 0; 
    skaityti(R,G,Z);
    spausdinti(R,G,Z);

    return 0;
}
