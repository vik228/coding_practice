#include <iostream>
#include <vector>
using namespace std;

bool interweavingStringsUtils(string one, string two, string three, int idx1, int idx2, string output) {
	if (idx1 >= one.length() and idx2 >= two.length()) {
		return (three == output);
	}
	if (idx1 >= one.length()) {
		output += two.substr(idx2, two.length() - idx2);
		return (three == output);
	}
	if (idx2 >= two.length()) {
		output += one.substr(idx1, one.length() - idx1);
		return (three == output);
	}
	output += one[idx1];
	bool firstTaken = interweavingStringsUtils(one, two, three, idx1+1, idx2, output);
    output.pop_back();
	output += two[idx2];
	bool secondTaken = interweavingStringsUtils(one, two, three, idx1, idx2+1, output);
    output.pop_back();
	return (firstTaken or secondTaken);
}

int main() {
    cout << interweavingStringsUtils("ab", "12", "1ab2", 0, 0, "") << "\n";
    return 0;
}
