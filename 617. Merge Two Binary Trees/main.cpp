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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* root3 = new TreeNode(0);
        if (root1) root3->val += root1->val;
        if (root2) root3->val += root2->val;
        if (!root1 && !root2) return nullptr;
        
        root3->left = mergeTrees((root1) ? root1->left : nullptr, (root2) ? root2->left : nullptr);
        root3->right = mergeTrees((root1) ? root1->right : nullptr, (root2) ? root2->right : nullptr);
        return root3;
    }
    // More elegent approach
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

int main(){
    Solution sol;
}
