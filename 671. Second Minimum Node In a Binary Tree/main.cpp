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
    int find(TreeNode* root , int val){
        if (!root) return -1;
        if (root->val > val) return root->val;
        int x = find(root->left , val);
        int y = find(root->right , val);
        if (x == -1) return y;
        if (y == -1) return x;
        return min(x,y);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        return find(root, root->val);
    }
};

int main(){
    Solution sol;
}
