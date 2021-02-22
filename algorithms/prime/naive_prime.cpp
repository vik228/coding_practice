#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;
bool primes[100000010];
bitset<100000010> all_primes;
void sieve(int n) {
  primes[0] = false;
  primes[1] = false;
  primes[2] = true;
  for (int i = 3; i < n; i++) {
    if (i%2 == 0) {
      primes[i] = false;
    } else {
      primes[i] = true;
    }
  }
  for (int i = 2; i*i < n; i++) {
    if (primes[i]) {
      for (int j = i*i; j < n; j += i) {
        primes[j] = false;
      }
    }
  }
}

void sieve_using_bitset(int n) {
  all_primes.set(0, 0);
  all_primes.set(1, 0);
  all_primes.set(2, 1);
  for (int i = 3; i < n; i++) {
    if (i%2 == 0) {
      all_primes.set(i, 0);
    }else {
      all_primes.set(i, 1);
    }
  }
  for (int i = 2; i*i < n; i++) {
    if (all_primes.test(i)) {
      for(int j = i*i; j < n; j += i) {
        all_primes.set(j, 0);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  sieve_using_bitset(n);
  cout << "primes till n are " << "\n";
  for (int i = 2; i < n; i++) {
    if (all_primes.test(i)) {
        cout << i << "\n";
    }
  }
  return 0;
}
