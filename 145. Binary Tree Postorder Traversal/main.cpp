#include <iostream>
#include <vector>
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
    void traversal(TreeNode* root, vector<int>& A){
        if (!root) return;
        traversal(root->left,A);
        traversal(root->right,A);
        A.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> A;
        traversal(root, A);
        return A;
    }
};

int main(){
    Solution sol;
}
