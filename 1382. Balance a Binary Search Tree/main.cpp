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
    void sortedlist(TreeNode* root, vector<int>& result){
        if (!root) return;
        sortedlist(root->left, result);
        result.push_back(root->val);
        sortedlist(root->right, result);
    }
    TreeNode* bal(vector<int> srtlist, int start, int end){
        if (start > end) return nullptr;
        TreeNode* tmp = new TreeNode(srtlist[(end+start)/2]);
        tmp->left = bal(srtlist, start, (end+start)/2-1);
        tmp->right = bal(srtlist, (end+start)/2+1, end);
        return tmp;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> result;
        sortedlist(root, result);
        return bal(result, 0, result.size()-1);
    }
};

int main(){
    Solution sol;
}
