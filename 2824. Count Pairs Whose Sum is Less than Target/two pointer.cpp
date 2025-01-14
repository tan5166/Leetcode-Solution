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
    int countPairs(vector<int>& nums, int target) {
        int size = nums.size();
        int result = 0;
        sort(nums.begin(),nums.end());
        int idx1 = 0;
        int idx2 = size - 1;
        while(idx1 != idx2){
            if (nums[idx1] + nums[idx2] < target){
                result += idx2-idx1;
                idx1++;
            }
            else idx2--;
        }
        return result;
    }
};

int main(){
    Solution sol;
}
