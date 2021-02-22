#include <iostream>
#include <cstdio>
#include <vector>
#define MOD 1000000007
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    vector<int> A;
    vector<int> B;
    int M;
    int N;
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
      int val;
      cin >> val;
      A.push_back(val);
    }

    for (int i = 0; i < N; i++) {
      int val;
      cin >> val;
      B.push_back(val);
    }
    vector<long long> fib;
    fib.push_back((A[M-1]*1LL) % MOD);
    fib.push_back((B[M-1]*1LL) % MOD);
    for (int i = 2; i < N; i++) {
      long long k  = ((fib[i-1] % MOD) + (fib[i-2] % MOD))%MOD;
      fib.push_back(k);
    }
    cout << fib[N-1] << "\n";
  }
  return 0;
}
