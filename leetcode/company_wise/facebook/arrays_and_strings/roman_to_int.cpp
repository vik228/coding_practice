#include <bits/stdc++.h>
using namespace std;

bool is_substraction(char a, char b) {
    string s = "";
    s += a;
    s += b;
    vector<string> v = {
                            "IV", "IX", 
                            "XL", "XC", 
                            "CD", "CM", 
                            "IL", "IC", 
                            "XD", "XM"
                        };
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == s) {
            return true;
        }
    }
    return false;
}
int romanToInt(string s) {
    unordered_map<char, int> umap {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int num = umap[s[s.length() - 1]];
    for (int i = s.length() - 2; i >= 0; i--) {
        if (is_substraction(s[i], s[i+1])) {
            num -= umap[s[i]];
        }else {
            num += umap[s[i]];
        }
    }
    return num;
}
int main() {
    string s;
    cin >> s;
    romanToInt(s);
    return 0;
}