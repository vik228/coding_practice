#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s) {
    if (s == "") {
        return 0;
    }
    int a[255];
    memset(a, -1, sizeof(a));
    int i = 0, j = 0;
    int max_len = 0;
    a[s[0]] = 0; 
    for (j = 1; j < s.length(); j++) {
        int idx = s[j];
        if (a[idx] != -1 and (a[idx] >= i and a[idx] < j)) {
            max_len = max(max_len, (j - i));
            i = a[idx] + 1; 
        }
        a[idx] = j;
    }
    if (a[s[j]] < i) {
        max_len = max(max_len, (j - i));
    }
    return max_len;
}
int main() {
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << "\n";
    return 0;
}