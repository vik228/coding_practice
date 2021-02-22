#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct suffix {
  pair<int, int> rank;
  int index;
}; 

int cmp(struct suffix a, struct suffix b) {
  return (a.rank.first == b.rank.first) ? ((a.rank.second < b.rank.second) ? 1 : 0) : ((a.rank.first < b.rank.first) ?1: 0);
}

vector<int> suffix_array_efficient(string s) {
  vector<int> suffix_indices;
  int n = s.length();
  struct suffix suffixes[n];
  for (int i = 0; i < n; i++) {
    int r = s[i] - 'a';
    int nr = ((i+1) < n)? (s[i + 1] - 'a'): -1;
    suffixes[i].index = i;
    suffixes[i].rank = make_pair(r, nr); 
  }
  sort(suffixes, suffixes + n, cmp);
  int indexes[n];
  for(int k = 4; k < 2*n; k = k*2) {
    int rank = 0;
    int prev_rank = suffixes[0].rank.first;
    indexes[suffixes[0].index] = 0;

    for (int i = i; i < n; i++) {
      if (suffixes[i].rank.first == prev_rank and suffixes[i].rank.second == suffixes[i-1].rank.second) {
        prev_rank = suffixes[i].rank.first;
        suffixes[i].rank.first = rank;
      }else {
        prev_rank = suffixes[i].rank.first;
        suffixes[i].rank.first = ++rank;
      }
      indexes[suffixes[i].index] = i;
    }
    for (int i = 0; i < n; i++) {
      int nextindex = suffixes[i].index + k/2;
      suffixes[i].rank.second = (nextindex < n)?suffixes[indexes[nextindex]].rank.first: -1;
    }
    sort(suffixes, suffixes + n, cmp);
  }
  for (int i = 0; i < n; i++) {
    suffix_indices.push_back(suffixes[i].index);
  }
  return suffix_indices;

}

int main()  {
  string s;
  cin >> s;
  vector<int> suffix_array = suffix_array_efficient(s);
  for (int i = 0; i < suffix_array.size(); i++) {
    cout << suffix_array[i] << ",";
  }
  cout << "\n";
  return 0;
}
