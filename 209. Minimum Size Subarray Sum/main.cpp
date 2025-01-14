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
        int n = nums.size();
        int left = 0;
        int right =0;
        int sum = 0;
        bool flag = false;
        int result = INT_MAX;
        for(int right = 0; right < n; right++){
            sum += nums[right];
            if (sum >= target){
                while(sum >= target){
                    sum -=nums[left];
                    left ++;
                }
                result = min(result, right - left + 2);
                flag = true;
            }
        }
        return flag ? result : 0;

        // for(int windowLength = 1; windowLength <= n; windowLength++){
        //     int sum = 0;
        //     for(int i=0; i<n; i++){
        //         sum += nums[i];
        //         if(i >= windowLength - 1){
        //             if (sum >= target){
        //                 return windowLength;
        //             }
        //             sum -= nums[i-windowLength+1];
        //         }
        //     }
        // }
        // return 0;
    }
};

int main(){
    Solution sol;
}
