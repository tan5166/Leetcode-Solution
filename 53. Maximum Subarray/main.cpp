#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map> 
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
    int maxSubArray(vector<int>& A) {
        //define dp[i] as largest sum of subarray with A[i] as last element of the subarray.
        int size = A.size();
        vector<int> dp(size,0);
        dp[0] = A[0];
        for(int i=1; i<size; i++){
            dp[i] = max(dp[i-1]+A[i],A[i]);
        }
        return dp[size-1];
    }
};

int main(){
    Solution sol;
}
