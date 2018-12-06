#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
rm bs_sqrt.out ; g++ -std=c++14 binary_search_sqrt.cpp -o bs_sqrt.out && ./bs_sqrt.out
*/

double sqrt_bs(int v, int& loop) {
    static double precision = 0.0000001;

    loop=0;
    if (v == 1) return 1;

    double dv = (double)v;
    double l = 1, h = dv;
    do {
        loop++;
        double m = (h-l)/2 + l;
        double f = dv-m*m;
        if (f > 0) {
            if (f <= precision) return m;
            l = m;
        } else {
            if ((-1.0 * f) <= precision) return m;
            h = m;
        }
    } while(true);
}

int main() {
    int loop = 0;
    cout.precision(6);
    cout <<  std::fixed << "sqrt_bs(4) = " << sqrt_bs(4, loop) << " , " << loop << "\n";
    cout <<  std::fixed << "sqrt_bs(2) = " << sqrt_bs(2, loop) << " , " << loop << "\n";
    cout <<  std::fixed << "sqrt_bs(81) = " << sqrt_bs(81, loop) << " , " << loop << "\n";
    cout <<  std::fixed << "sqrt_bs(99) = " << sqrt_bs(99, loop) << " , " << loop << "\n";
    return 0;
}

