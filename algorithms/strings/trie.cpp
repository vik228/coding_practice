#include <bits/stdc++.h>
using namespace std;
const int ALPHABET_SIZE = 26;

struct TrieNode {
  struct TrieNode *children[ALPHABET_SIZE];
  bool isEndOfWord;
  int idx;
  int nodeNum;
  int maxNode;
};

vector<string> below10 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
vector<string> below20 = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
vector<string> below100 = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string solve(int num) {
  string s;
  if (num == 0) {
    return 0;
  }
  if (num < 10) {
    s = below10[num];
  } else if (num < 20) {
    s = below20[num-10];
  } else if (num < 100) {
    s = below100[num/10] + " " + solve(num%10);
  } else if (num < 1000) {
    s = solve(num/100) + " Hundred " + solve(num%100);
  } else if (num < 1000000) {
    s = solve(num/1000) + " Thousands " + solve(num%1000);
  } else if (num < 1000000000) {
    s = solve(num/1000000) + " Million " + solve(num%1000000);
  } else {
    s = solve(num/1000000000) + " Billion " + solve(num%1000000000);
  }
  s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
  return s;
}

TrieNode *getNode(void) {
  TrieNode *node = new TrieNode();
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    node->children[i] = NULL;
  }
  node->isEndOfWord = false;
  node->idx = -1;
  return node;
}

void insert(string pattern, TrieNode* root) {
  TrieNode *currentNode = root;
  int i;
  for (i = 0; i < pattern.size(); i++) {
    int index = pattern[i] - 'a';
    if (currentNode->children[index] == NULL) {
      TrieNode* node = getNode();
      root->maxNode = root->maxNode + 1;
      node->nodeNum = root->maxNode;
      currentNode->children[index] = node;
    }
    currentNode = currentNode->children[index];
  }
  currentNode->isEndOfWord = true;
  currentNode->idx = i;
}

bool search(string text, int start,TrieNode *root) {
  TrieNode *currentNode = root;
  for (int i = start; i < text.size(); i++) {
    if (currentNode != NULL) {
      break;
    } else {
      if (text[i] != '.') {
        currentNode = currentNode->children[(text[i] - 'a')];
      } else {
        TrieNode* temp = currentNode;
        for (int j = 0; j < 26; j++) {
          currentNode = temp->children[j];
          if (search(text, i+1, currentNode)) {
            return true;
          }
        }
      }
    }
  }
  return currentNode != NULL and currentNode->isEndOfWord;
}

void display(TrieNode *root) {
    int i;
    for (i = 0; i < ALPHABET_SIZE; i++) {
      if (root->children[i] != NULL) {
        cout << root->nodeNum - 1 << "->" << root->children[i]->nodeNum - 1 << ":" << char(i + 'a') << "\n";
        display(root->children[i]);
      }
    }
}

TrieNode* build_trie_and_display(vector<string> patterns, bool print_tree) {
  TrieNode *root = getNode();
  root->nodeNum = 1;
  root->maxNode = 1;
  for (int i = 0; i < patterns.size(); i++) {
    insert(patterns[i], root);
  }
  if (print_tree)
    display(root);
  return root;
}

vector<int> trie_matching() {
  string text;
  vector<string> patterns;
  cin >> text;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    patterns.push_back(s);
  }
  TrieNode* root = build_trie_and_display(patterns, false);
  vector<int> ans;
  for (int i = 0; i < text.length(); i++) {
    int j = i;
    for (j = i; j < text.length(); j++) {
      string sub_string = text.substr(i, j - i + 1);
      TrieNode* searchedNode = search(sub_string, root);
      if (searchedNode != NULL) {
        ans.push_back(i);
      }
      break;
    }
  }
  return ans;
}
int main() {
  //TrieNode* root = build_trie_and_display(true);
  vector<int> ans = trie_matching();
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
