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
    pair<int, int> SumCount(TreeNode* root, int& count){
        if (!root) return {0,0};
        pair<int, int> left = SumCount(root->left, count);
        pair<int, int> right = SumCount(root->right, count);

        int sum = root->val + left.first + right.first;
        int totalnode = 1 + left.second + right.second;
        if(sum/totalnode == root->val) count++;
        return {sum, totalnode};
    }

    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        SumCount(root,count);
        return count;
    }
};

int main(){
    Solution sol;
}
