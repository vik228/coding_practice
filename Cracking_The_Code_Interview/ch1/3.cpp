#include <iostream>
#include <cstdio>
using namespace std;
bool isPermutation (string s1, string s2)
{
        if(s1.length() != s2.length()) {
            return false;
        }
        static int table[26];
        for(int i=0; i<s1.length(); i++) {
            table[s1[i]-'a']++;
        }
        for(int i=0; i<s2.length(); i++) {
            table[s2[i]-'a']--;
            if (table[s2[i]-'a']<0) {
                return false;
            }
        }
        return true;
}
int main()
{
        string s1, s2;
	cin >> s1 >> s2;
	if (s1.length() != s2.length())
	        cout << "NO\n";
	else if (isPermutation (s1, s2))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}

