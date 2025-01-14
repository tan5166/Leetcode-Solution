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
    int sumLeft(TreeNode* parent, TreeNode* me){
        if (!me) return 0;
        if (!me->left && !me->right){
            if (parent->left == me && !me->left){
                return me->val;
            }
            else return 0;
        }
        return sumLeft(me, me->left) + sumLeft(me, me->right);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 0;
        return sumLeft(root, root->left) + sumLeft(root, root->right);
    }
};

int main(){
    Solution sol;
}
