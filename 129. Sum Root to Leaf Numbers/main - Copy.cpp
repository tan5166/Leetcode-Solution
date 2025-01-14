#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <numeric>
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
    int sumNumbers(TreeNode *root)
    {
        return dfs(root);
    }
    int dfs(TreeNode *root, int pathsum)
    {
        if (!root)
            return 0;
        pathsum = 10 * pathsum + root->val;
        if (!root->left && !root->right)
            return pathsum;
        return dfs(root->left, pathsum) + dfs(root->right, pathsum);
    }
};

int main()
{
    Solution sol;
}
