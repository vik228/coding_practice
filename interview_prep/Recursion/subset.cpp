#include <bits/stdc++.h>
using namespace std;
vector<string> ans;

void generateSubset(string s,string output) {
    if (s.length() == 0) {
        ans.push_back(output);
        return;
    }
    string op1 = output;
    string op2 = output;
    op2.push_back(s[0]);
    s.erase(s.begin() + 0);
    generateSubset(s, op1);
    generateSubset(s, op2);
}
int main() {
    generateSubset("abc","");
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}