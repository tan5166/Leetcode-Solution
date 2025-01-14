#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if (!root) return false;
        int value = root->val;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()){
            TreeNode* tmp = s.top();
            s.pop();
            if (tmp->val != value) return false;
            if (tmp->left) s.push(tmp->left);
            if (tmp->right) s.push(tmp->right);
        }
        return true;
    }
};

int main(){
    Solution sol;
}
