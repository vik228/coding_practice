#include <iostream>

using namespace std;

#define WORDSIZE 32
#define BITS_WS 5
#define MASK 0x1f

void set(int bv[], int i) {
  bv[i >> BITS_WS] |= (1 << (i & MASK));

}

int get(int bv[], int i) {
  return bv[i>>BITS_WS] & (1 << (i & MASK));
}

int main() {
  int bv[32] = {0};
  int s1[] = {32, 5, 0};
  int s2[] = {32, 4, 5, 0};
  for (int i = 0; s1[i]; i++) {
    set(bv, s1[i]);
  }
  for (int i = 0; s2[i]; i++) {
    if (get(bv, s2[i]) == 1) {
      cout << s2[i] << "\n";
    }
  }
  return 0;
}
