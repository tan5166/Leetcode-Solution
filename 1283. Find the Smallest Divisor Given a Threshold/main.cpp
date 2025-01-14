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
    bool SmallthanThres(vector<int>& nums, int threshold, int d){
        int result = 0; 
        for(int i = 0; i <nums.size(); i++){
            result += ceil((double) nums[i]/d);
        }
        return (result <= threshold);
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(), nums.end());
        int ans;
        int left = 1;
        int right = *nums.end();
        while(left <= right){
            int mid = left + (right - left)/2;
            if(SmallthanThres(nums, threshold, mid)){
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1; 
        }
        return ans;
    }
};

int main(){
    Solution sol;
}
