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
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            if (tmp->left) s.push(tmp->left);
            if (tmp->right) s.push(tmp->right);
            if (!tmp->left && !tmp->right) v.push_back(tmp->val);
        }
        return v;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        
    }
};

int main(){
    Solution sol;
}
