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
    int Diff(TreeNode* root, int min, int max){
        if (!root) return 0;
        int maxi = max(maxancestor, root->val);
        max(Diff(root->left, maxi), Diff(root->right, maxi))
        return abs(maxancestor)
    }
    int maxAncestorDiff(TreeNode* root) {
        
    }
};

int main(){
    Solution sol;
}
