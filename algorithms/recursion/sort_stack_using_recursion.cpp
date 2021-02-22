#include <bits/stdc++.h>
using namespace std;

void insert(stack<int, vector<int>>& s, int temp) {
    if(s.empty() or s.top() <= temp) {
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s, temp);
    s.push(val);
}

void sort(stack<int, vector<int>>& s1) {
    if (s1.empty()) {
        return;
    }
    int temp = s1.top();
    s1.pop();
    sort(s1);
    insert(s1, temp);
}

int main() {
    vector<int> v1 = {1,3,0,5,2,1};
    stack<int, vector<int>> s1(v1);
    sort(s1);
    while(!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << "\n";
}