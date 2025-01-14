#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
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
    int minimumTotal(vector<vector<int>>& A) {
        vector<vector<int>> dp(A.size(),vector<int> (A[A.size()-1].size(),0));
        dp[0][0] = A[0][0];
        int result = dp[0][0];
        for(int i=1; i<A.size();i++){
            result = INT32_MAX;
            for(int j=0; j<A[i].size();j++){
                if (j==0)
                    dp[i][j] = A[i][j] + dp[i-1][j];
                else if (j==A[i].size()-1)
                    dp[i][j] = A[i][j] + dp[i-1][j-1];
                else dp[i][j] = A[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
                result = min(result,dp[i][j]);
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
}
