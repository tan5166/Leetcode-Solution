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
        for(int i = 0; i<size-1; i++){
            for(int j=i+1; j<size; j++){
                if(nums[i]+nums[j] < target) result++;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
}
