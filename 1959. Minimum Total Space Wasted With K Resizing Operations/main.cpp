#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <bitset>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    int dp[205][205];
    int dfs(vector<int>& nums, int k, int index){
        if(index == nums.size()) return 0;
        if(k < 0) return INT_MAX;
        if (dp[index][k] != -1) return dp[index][k];
        long long tmp = LONG_MAX, sum = 0, maxi = 0;
        for(int i = index; i < nums.size(); i++){
            sum += nums[i];
            maxi = max(maxi, (long long) nums[i]);
            tmp = min(tmp, maxi * (i-index + 1) - sum + dfs(nums, k-1, i+1));
        }
        dp[index][k] = tmp;
        return dp[index][k];
    }
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        return dfs(nums,k,0);
    }
};

int main(){
    Solution sol;
}
