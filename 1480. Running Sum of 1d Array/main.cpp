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
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        result[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            result[i] = result[i-1] + nums[i];
        }
        return result;
    }
};

int main(){
    Solution sol;
}
