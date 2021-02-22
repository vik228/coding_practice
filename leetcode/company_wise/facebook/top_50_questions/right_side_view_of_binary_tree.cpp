#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* front = q.front();
            q.pop();
            if (front) {
                if (i == size-1) {
                    ans.push_back(front->val);
                }
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
        }
    }
    return ans;
}
int main() {
    return 0;
}