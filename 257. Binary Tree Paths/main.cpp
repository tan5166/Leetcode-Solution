#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string> 
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
private:
    vector<string> v;
public:
    vector<string> binaryTreePaths(TreeNode* root, string s = "") {
        if (!root) return v;
        if (!root ->left && !root->right){
             v.push_back(s + to_string(root->val));
        }
        binaryTreePaths(root->left, s + to_string(root->val) + "->");
        binaryTreePaths(root->right, s + to_string(root->val) + "->");
        return v;
    }
};

int main(){
    Solution sol;
}
