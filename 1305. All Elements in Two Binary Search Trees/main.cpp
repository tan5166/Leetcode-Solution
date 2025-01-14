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
    void inorder(TreeNode* root1, vector<int>& list){
        if (!root1) return;
        inorder(root1->left, list);
        list.push_back(root1->val);
        inorder(root1->right, list)
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result;
        inorder(root1, result);
        inorder(root2, result);
        sort(result.begin(),result.end());
        return result;
    }
};

int main(){
    Solution sol;
}
