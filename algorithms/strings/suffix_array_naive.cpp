#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int main() {
	vector< pair<string, int> > v;
	string s;
	cin >> s;
	v.push_back(make_pair(s, 0));
	for (int i = 1; i < s.length(); i++) {
		string suffix = s.substr(i, s.length() - i);
		v.push_back(make_pair(suffix, i));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << ",";
	}
	cout << "\n";
	return 0;
}
