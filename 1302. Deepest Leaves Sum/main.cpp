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
    int maxdepth(TreeNode* root){
        if (!root) return 0;
        return 1 + max(maxdepth(root->left),maxdepth(root->right));
    }
    int deepestLeavesSum(TreeNode* root) {
        int depth = maxdepth(root);
        int result = 0;
        // do bfs
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* tmp = q.front();
                q.pop();
                if (depth == 1) result += tmp->val;
                if (tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            depth--;
        }
        return result;
    }
};

int main(){
    Solution sol;
}
