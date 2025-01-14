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
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1,0);
        for(int i=0; i< arr.size(); i++){
            int max_kokoda = arr[i];
            for(int j=0; j<=min(k-1,i) ;j++){
                max_kokoda = max(arr[i-j],max_kokoda);
                dp[i+1] = max(dp[i+1],max_kokoda*(j+1) + dp[i-j]);
            }
        }
        // for (int i = 0; i < dp.size(); ++i) {
        // cout << dp[i] << " ";
        // }
        // cout << endl;
        return dp[arr.size()];
    }
};

int main(){
    Solution sol;
    vector<int> v = {1,15,7,9,2,5,10};
    int k = 3;
    sol.maxSumAfterPartitioning(v, k);
}
