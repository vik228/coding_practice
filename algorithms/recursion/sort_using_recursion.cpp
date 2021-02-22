#include <bits/stdc++.h>
using namespace std;

void insert(vector<int>& v1, int temp) {
    if (v1.size() == 0 || v1.back() <= temp) {
        v1.push_back(temp);
        return;
    }
    int val = v1.back();
    v1.pop_back();
    insert(v1, temp);
    v1.push_back(val);
}

void sort(vector<int>& v1) {
    if (v1.size() == 0) {
        return;
    }
    int temp = v1.back();
    v1.pop_back();
    sort(v1);
    insert(v1, temp);
}

int main() {
    vector<int> v1 = { 2, 3, 1, 5 };
    sort(v1);
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " " << "\n";
    }
    return 0;
}