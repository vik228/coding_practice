#include <iostream>
#include <fstream>

#define WORDSIZE 32
#define BITS_WS 5
#define MASK 0x1f
using namespace std;

void set (int bv[], int i) {
  bv[i >> WORDSIZE] |= (1 << (i & MASK));
}

int get(int bv[], int i) {
  return bv[i>>BITS_WS] & (1 << (i & MASK));
}

int main() {

  string line;
  ifstream myfile ('sort_file.in');
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      cout << line << "\n";
      break;
    }
  }
  return 0;

}


