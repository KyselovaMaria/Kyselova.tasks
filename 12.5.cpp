#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;


int main() {
    ifstream fin;
    ofstream fout;
    unsigned long long int a;
    fin.open("f1.txt");
    fout.open("f2.txt");
    fout << fixed << setprecision(3);
    
    while (true) {
        fin >> a;
        if (!fin.good())
            break;
        fout << sqrt(a) << endl;
    }

    fin.close();
    fout.close();

    return 0;
}