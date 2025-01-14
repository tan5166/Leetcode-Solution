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
    void flatten(TreeNode *root)
    {
        TreeNode *end = nullptr;
        dfs(root, end);
    }
    void dfs(TreeNode *root, TreeNode *end)
    {
        if (!root)
            return;

        TreeNode *rightree = root->right;

        if (end)
        {
            end->right = root;
            end->left = nullptr;
        }

        end = root;
        dfs(root->left, end);
        dfs(rightree, end);
    }
};

int main()
{
    Solution sol;
}
