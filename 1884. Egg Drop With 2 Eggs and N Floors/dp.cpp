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
    int twoEggDrop(int n){
        vector<int> v(n+1,0);
        vector<vector<int>> dp(n+1,v);
        dp[1][1] = 1;
        v[1] = 1;
        // row: 建築物有的樓層
        // col: 假如我們在第 col 丟第一個雞蛋
        // dp[row][col]: 建築物只有row層的情況下，我們在col丟第一顆雞蛋，我們最小移動次數
        for(int i=2 ; i<n+1 ; i++){
            int minmove = n+1;
            for(int j=1 ; j<= i ; j++){
                dp[i][j] = max(j,1+v[i-j]);
                minmove = min(minmove,dp[i][j]);
            }
            v[i] = minmove;
        }
        return v[n];
    }
};

int main(){
    Solution sol;
}
