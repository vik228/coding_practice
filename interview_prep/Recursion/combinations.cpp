#include<bits/stdc++.h>
using namespace std;

vector<string> combinations;
void combinationUtils(string characters, int r, string output, int idx) {
    if (output.length() == r) {
        combinations.push_back(output);
    }
    for (int i = idx; i < characters.length(); i++) {
        output.push_back(characters[i]);
        combinationUtils(characters, r, output, i+1);
        output.pop_back();
    }
}

string solve(string str) {
    unordered_map<char, int> umap;
	int start_i = 0;
	int maxLen = 0;
	int i = 0;
	for (int j = 0; j < str.length(); j++) {
        cout << "hello " << start_i << " " << maxLen << "\n";
		if (umap.find(str[j]) != umap.end()) {
            if (umap[str[j]] > i)
			    i = umap[str[j]] + 1; 
		}
		umap[str[j]] = j;
		if (j - i + 1 >= maxLen) {
            cout << start_i << " " << maxLen << "\n";
			maxLen = j - i + 1;
			start_i = i;
		}
	}
    //cout << start_i << " " << maxLen << "\n";
	return str.substr(start_i, maxLen);
}

int main() {
    solve("abcdeabcdefc");
    // combinationUtils("abcd", 2, "", 0);
    // for (int i = 0; i < combinations.size(); i++) {
    //     cout << combinations[i] << " ";
    // }
    // cout << "\n";
    // return 0;
}