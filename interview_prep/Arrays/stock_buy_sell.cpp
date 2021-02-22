#include <bits/stdc++.h>
using namespace std;

tuple<int, int> find_buy_sell_stock_prices(int* array, int size) { 
  int low = -1;
  int high = -1;
  int i = 0;
  int j;
  int max_so_far = -2147483647 - 1;
  for (j = 1; j < size; j++) {
    int diff = array[j] - array[i];
    if (diff > max_so_far) {
      max_so_far = diff;
      low = array[i];
      high = array[j];
    }
    if (array[j] < array[i]) {
      i = j;
    }
  }
  tuple<int, int> result(std::make_pair(low, high));
  return result; // t is a tuple with (high, low) price values
}