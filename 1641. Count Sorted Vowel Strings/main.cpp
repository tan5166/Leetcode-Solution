#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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
    int countVowelStrings(int n) {
        int dp[5][2];
        for(int i=0;i<5;i++){
            dp[i][0] = 1; dp[i][1] = 0;
        }
        for(int j = 1; j<n;j++){
            for(int i=1;i<5;i++){
                dp[i][1] = dp[i-1][0] + dp[i-1][1]; 
            }
            for(int i=1;i<5;i++){
                dp[i][0] += dp[i][1]; 
            }
        }
        int sum = 0;
        for(int i=0;i<5;i++){
            sum += dp[i][0];
        }
        return sum;
    }
};

int main(){
    Solution sol;
}
