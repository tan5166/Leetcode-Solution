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
public:
    vector<int> dfs(TreeNode* root){
        vector<int> v;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* tmp = s.top();
            s.pop();
            if (tmp->left) s.push(tmp->left);
            if (tmp->right) s.push(tmp->right);
            if (!tmp->left && !tmp->right) v.push_back(tmp->val);
        }
        return v;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1 = dfs(root1);
        vector<int> v2 = dfs(root2);
        if (v1.size()!= v2.size()) return false;
        else return v1 == v2;
    }
};

int main(){
    Solution sol;
}
