#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int f = 1;
        int n, x;
        cin >> n >> x;
        n -= 2;
        if (n > 0) {
            if (n%x == 0) {
                f += n/x;
            } else {
                f += n/x + 1;
            }
        }
        cout << f << "\n";
    }
    return 0;
}