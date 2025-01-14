#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> s;
        if (!root) return result;
        s.push(root);
        while(!s.empty()){
            int n = s.size();
            vector<int> p;
            for (int i = 0; i< n; i++){
                TreeNode* tmp = s.front();
                p.push_back(tmp->val);
                s.pop();
                if (tmp->left) s.push(tmp->left);
                if (tmp->right) s.push(tmp->right);
            }
            result.push_back(p);
        }
        return result;
    }
};

int main(){
    Solution sol;
}
