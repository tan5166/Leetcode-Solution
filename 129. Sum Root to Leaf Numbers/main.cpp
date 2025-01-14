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
        vector<int> result;
        dfs(root, 0, result);
        return accumulate(result.begin(), result.end(), 0);
    }
    void dfs(TreeNode *root, int value, vector<int> &result)
    {
        if (!root->left && !root->right)
        {
            result.push_back(value + root->val);
        }
        if (root->left)
            dfs(root->left, value + 10 * root->val, result);
        if (root->right)
            dfs(root->right, value + 10 * root->val, result);
    }
};

int main()
{
    Solution sol;
}
