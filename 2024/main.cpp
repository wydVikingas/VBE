#include <iostream>
#include <fstream>

using namespace std;

// konstantos
const int VPIlg = 30;
const int ValIlg = 20;

// Olimpiniu struktura
struct Olimpines {
    char kodas[VPIlg];
    double rezult;
};

// Pasiekimu struktura
struct Pasiekimai {
    char kodas[VPIlg];
    double grezult;
    int data;
    char valstybe[ValIlg];
};

void skaitymas(Olimpines zaidejai[], int &n) {
    ifstream fd("Olimpines.txt");
    fd >> n;
    for (int i = 0; i < n; i += 1) {
        fd >> zaidejai[i].kodas;
        fd >> zaidejai[i].rezult;
    }
    fd.close();
}

void rasymas(Olimpines zaidejai[], int n) {
    ofstream fo("Rezultatai.txt");
    
    for(int i = 0; i < n; i += 1) {
        fo << zaidejai[i].kodas << " ";
        fo << zaidejai[i].rezult << endl;
    }

    fo.close();
}

int main() {
    int n;
    Olimpines zaidejai[32];
    skaitymas(zaidejai, n);
    rasymas(zaidejai, n);
    return 0;
}
