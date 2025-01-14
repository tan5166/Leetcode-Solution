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
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int result = INT_MAX;
        bool gotAns = false;
        for(int windowLength = l; windowLength <= r; windowLength++){
            int sum = 0;
            for(int i = 0; i+windowLength-1 < n; i++){
                sum += nums[i];
                if(i> windowLength-1){
                    if (sum>0){
                        result = min(sum, result);
                        gotAns = true;
                    }
                    sum -= nums[i];
                }
            }
        }
        return gotAns ? result : -1;
    }
};

int main(){
    Solution sol;
}
