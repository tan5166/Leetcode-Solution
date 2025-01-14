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
    void traver(TreeNode* root, TreeNode* parent, TreeNode* grand, int& result){
        if (!root) return;
        if(grand && grand->val%2 == 0){
            result += root->val;
        }
        traver(root->left, root, parent, result);
        traver(root->right, root, parent, result);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int result = 0;
        traver(root, nullptr, nullptr, result);
        return result;
    }
};

int main(){
    Solution sol;
}
