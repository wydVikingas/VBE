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

void skaitymas(int &n) {
    ifstream fd("Olimpines.txt");
    fd >> n;
    for (int i = 0; i < n; i += 1) {
        cout << 'a';
    }
    fd.close();
}

int main() {
    int n;
    skaitymas(n);
    return 0;
}
