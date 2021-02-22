#include <bits/stdc++.h>
using namespace std;

pair<vector<char>, bool> process(string pattern) {
	bool switched = (pattern[0] == 'y');
	vector<char> patternArr;
	for (int i = 0; i < pattern.size(); i++) {
		char ch = pattern[i];
		if (switched) {
			ch = (pattern[i] == 'y') ? 'x' : 'y'; 
		}
		patternArr.push_back(ch);
	}
	return {patternArr, switched};
}

pair<unordered_map<char,int>, int> getPatternCharsCount(vector<char> pattern) {
	unordered_map<char, int> umap;
	int firstYPosition = -1;
	for (int i = 0; i < pattern.size(); i++) {
		umap[pattern[i]] += 1;
		if (pattern[i] == 'y' and firstYPosition == -1) {
			firstYPosition = i;
		}
	}
	return {umap, firstYPosition};
}

bool validXAndY(string x, string y, vector<char>& pattern, string text) {
	string potentialText = "";
	for (int i = 0; i < pattern.size(); i++) {
		if (pattern[i] == 'x') {
			potentialText += x;
		} else {
			potentialText += y;
		}
	}
	cout << x << " " << y << " " << potentialText << "\n"; 
	return (potentialText == text);
}
vector<string> patternMatcher(string pattern, string str) {
  // Write your code here.
	/*
		totalYChars = freq*len(y)
		totalXChars + totalYChars = len(str)
		totalYChars = len(str) - totalXChars
	*/
	pair<vector<char>, bool> p1 = process(pattern);
	pair<unordered_map<char, int>, int> p2 = getPatternCharsCount(p1.first);
	
	unordered_map<char, int> frequency = p2.first;
	int firstYPos = p2.second;
	string x = "";
	string y = "";
	int total_len = str.length();
	int i = 0;
	while(!validXAndY(x, y, p1.first, str)) {
		x = str.substr(0, i + 1);
		int lenX = x.length();
		int totalXChars = frequency['x']*lenX;
		int lenY = (total_len - totalXChars)/frequency['y'];
		int yPos = firstYPos*lenX;
		y = str.substr(yPos, lenY);
		i++;
	}
	if (p1.second) {
		return {y, x};
	}
	return {x, y};
}


int main() {
    patternMatcher("yxx", "yomama");
    return 0;
}
