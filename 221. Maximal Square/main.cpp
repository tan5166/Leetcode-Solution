#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
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
    int maximalSquare(vector<vector<char>>& A) {
        int result = 0;
        vector<vector<int>> dp(A.size(), vector<int>(A[0].size(), 0));
        for(int i = 0; i<A.size();i++){
            for(int j= 0; j<A[0].size();j++){
                if(A[i][j]>'0' && i>0 && j>0)
                    dp[i][j] =  min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
                else dp[i][j] = A[i][j]-'0';
                result = max(result, dp[i][j]);
            }
        }
        return result * result;
    }
};

int main(){
    Solution sol;
}
