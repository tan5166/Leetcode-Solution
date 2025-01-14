#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
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
    bool valid(TreeNode* root, TreeNode* low, TreeNode* high){
        if (root == nullptr) return true;
        if ((low!= nullptr && root->val <= low->val) || (high!= nullptr && root->val >= high->val)) return false;
        return (valid(root->left, low, root) && valid(root->right, root, high));
    }
    bool isValidBST(TreeNode* root) {
        return valid(root, nullptr, nullptr);
    }
};

int main(){
    Solution sol;
}
