#include <iostream>
#include <fstream>

using namespace std;

int skaiciuoti(int n1, int n3, int n5, int k, int islaidos, int p1, int p3, int p5) {
    //krc
}

int main() {
    int n1, n3, n5, k;
    int islaidos, p1, p3, p5;
    
    ifstream fin("U1.txt");
    fin >> n1 >> n3 >> n5 >> k >> islaidos >> p1 >> p3 >> p5;
    fin.close();

    skaiciuoti(n1, n3, n5, k, islaidos, p1, p3, p5);

    return 0;
}
