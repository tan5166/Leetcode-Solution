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
    void resursion(TreeNode* root, int targetSum, int pathsum, vector<int> path ,vector<vector<int>>& result){
        if(!root->left && !root->right && pathsum == targetSum){
            result.push_back(path);
            return;
        }
        if(!root->left && !root->right && pathsum != targetSum){
            return;
        }
        vector<int> tmp = path;
        tmp.push_back(root->val);
        resursion(root->left, targetSum, pathsum + root->val,tmp, result);
        resursion(root->right, targetSum, pathsum + root->val, tmp,result);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        resursion(root,targetSum, 0, path ,result);
        return result;
    }
};

int main(){
    Solution sol;
}
