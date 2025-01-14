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
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = n;
        for(int i = n-1; i>=0 ; i--){
            if(nums[i] > nums[i-1]){
                index = i-1;
                break;
            }
        }
        if (index==n){
            sort(nums.begin(),nums.end());
        }
        int smallest = INT_MAX;
        int change;
        for(int i = index+1;i<n;i++){
            if(nums[i] > nums[index] && smallest>nums[i]){
                change = i;
                smallest = nums[i];
            }
        }
        swap(nums[index], nums[change]);
        sort(nums.begin() + index + 1,nums.end());
    }
};

int main(){
    Solution sol;
}
