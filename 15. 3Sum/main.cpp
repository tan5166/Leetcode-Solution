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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> r;
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size();i++){
            if (i>1 && nums[i] == nums[i-1]) continue;
            int target = -1*nums[i];
            int left = i+1;
            int right = nums.size() - 1;
            while(left < right){
                if (nums[left] + nums[right] == target){
                    s.insert({nums[i],nums[left],nums[right]});
                    left++;
                }
                else if (nums[left] + nums[right] > target){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        for(auto t:s){
            r.push_back(t);
        }
        return r;
    }
};

int main(){
    Solution sol;
}
