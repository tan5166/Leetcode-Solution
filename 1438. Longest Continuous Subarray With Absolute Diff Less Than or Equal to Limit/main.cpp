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
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int left = 0;
        int result = 0;
        deque<int> maxi;
        deque<int> mini;

        for(int right = 0; right < n; right++){
            while (!maxi.empty() && nums[maxi.back()] <= nums[right]) {
                maxi.pop_back();
            }
            maxi.push_back(right);

            while (!mini.empty() && nums[mini.back()] >= nums[right]) {
                mini.pop_back();
            }
            mini.push_back(right);

            while (nums[maxi.front()] - nums[mini.front()] > limit){
                left++;
                if (maxi.front() == left - 1) {
                    maxi.pop_front();
                }
                if (mini.front() == left - 1) {
                    mini.pop_front();
                }
            }
            result = max(result, right-left+1);
        }
        return result;
    }
    // vector<vector<int>> maxi(n, vector<int>(n,0));
    // vector<vector<int>> mini(n, vector<int>(n,0));

    // for(int i = 0 ; i< n; i++){
    //     maxi[i][i] = nums[i];
    //     mini[i][i] = nums[i];
    // }

    // for(int i = 0; i < n; i++){
    //     for(int j = i+1; j< n; j++){
    //         maxi[i][j] = max(maxi[i][j-1], nums[j]);
    //         mini[i][j] = min(mini[i][j-1], nums[j]);
    //     }
    // }
};

int main(){
    Solution sol;
}
