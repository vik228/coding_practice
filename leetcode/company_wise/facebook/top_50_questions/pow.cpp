#include <bits/stdc++.h>
using namespace std;
double myPow(double x, int n) {
    long long N = n;
    if (N < 0) {
        x = 1.0/x;
        N = -N;
    }
    double res = 1.0;
    while(N > 0) {
        if (N%2 == 1) {
            res = res*x;
        }
        x = x*x;
        N /= 2;
    }
    return res;
}
int main() {
    cout << myPow(2.000, -4) << "\n";
}