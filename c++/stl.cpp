#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<int> A = {1,2,3,4};

  cout << A[1] << "\n";

  sort(A.begin(), A.end()); //O(NlogN)
}
