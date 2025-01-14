#include <iostream>
#include <vector>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        if (size==0) return nullptr;

        int mid = size/2;

        TreeNode* left = nullptr;
        if (mid>0){
            vector<int> leftvec(nums.begin(),nums.begin()+mid);
            left = sortedArrayToBST(leftvec);
        }

        TreeNode* right = nullptr;
        if (mid+1 < size){
            vector<int> rightvec(nums.begin()+mid+1,nums.end());
            right = sortedArrayToBST(rightvec);
        }

        TreeNode* root = new TreeNode(nums[mid], left, right);
        return root;
    }
};

void inorderPrint(TreeNode* root){
    if (!root){
        cout<< "null ";
        return;
    }
    cout<< root->val << " ";
    inorderPrint(root->left);
    inorderPrint(root->right);
    return;
}


int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4,5};
    TreeNode* root = sol.sortedArrayToBST(nums);
    inorderPrint(root);
}
