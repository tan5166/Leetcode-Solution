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
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX;
        int left = 0;
        int sumofwin = 0;
        for(int right=0; right < nums.size(); right++){
            sumofwin += nums[right];
            while(sumofwin >= target){
                result = min(result, right - left + 1);
                sumofwin -= nums[left];
                left ++;
            }
        }
        return (result == INT_MAX) ? 0 : result;
    }
};

int main(){
    Solution sol;
}
