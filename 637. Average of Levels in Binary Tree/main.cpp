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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> s;
        if (!root){
            return result;
        }
        s.push(root);
        while(!s.empty()){
            int size = s.size();
            long sum = 0;
            for (int i = 0; i<size; i++){
                TreeNode* tmp = s.front();
                s.pop();
                sum += tmp->val;
                if (tmp->left) s.push(tmp->left);
                if (tmp->right) s.push(tmp->right);
            }
            result.push_back((double)sum/size);
        }
        return result;
    }
};

int main(){
    Solution sol;
}
