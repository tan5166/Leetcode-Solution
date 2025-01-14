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
    int countMaxOrSubsets(vector<int>& nums) {
        int max = nums[0];
        for(int i=1; i<nums.size(); i++){
            max |= nums[i];
        }
    int count = 0;
    SubsetCount(nums, 0, 0, max , count);
    return count;
    }
    void SubsetCount(vector<int>& nums, int index, int curSum, int max ,int& count){
        for(int i = index; i<nums.size(); i++){
            int prev = curSum;
            curSum |= nums[i];
            if (curSum == max) count ++;
            SubsetCount(nums, i + 1, curSum, max , count);
            curSum = prev; 
        }
    }
};

int main(){
    Solution sol;
}
