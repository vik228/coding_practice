#include <bits/stdc++.h>
using namespace std;


void insertionSort(vector<int>& v1) {
    int i = 1;
    int n = v1.size();
    while(i < n) {
        int key = v1[i];
        int j = i-1;
        while (j >= 0 and v1[j] > key) {
            v1[j+1] = v1[j];
            j--;
        }
        v1[j+1] = key;
        i++;
    }
}

int main() {
    vector<int> v1 = {4,3,2,10,12,1,5,6};
    insertionSort(v1);
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << "\n";
    return 0;
}