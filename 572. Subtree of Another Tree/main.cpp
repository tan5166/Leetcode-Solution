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
    bool check(TreeNode* root, TreeNode* subRoot){
        if ((root && !subRoot)||(!root && subRoot)) return false;
        if (!root && !subRoot) return true;
        return (root->val == subRoot->val) && check(root->left, subRoot->left) && check(root->right , subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (root->val == subRoot->val){
            if(check(root, subRoot)) return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

int main(){
    Solution sol;
}
