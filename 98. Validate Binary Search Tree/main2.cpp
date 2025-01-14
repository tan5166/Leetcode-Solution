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
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return valid(root, nullptr, nullptr);
    }
    bool valid(TreeNode *root, TreeNode *low, TreeNode *high)
    {
        if (!root)
            return true;
        if ((low && root->val <= low->val) || (high && high->val <= root->val))
            return false;
        return valid(root->left, low, root) && valid(root->right, root, high);
    }
};

int main()
{
    Solution sol;
}
