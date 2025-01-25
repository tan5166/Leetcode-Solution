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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int CanBuy = 0;
        int CanSold = -prices[0];
        int OnlyRest = INT_MIN;
        for(int i = 1; i < n; i++){
            int prevOnlyRest = OnlyRest;
            OnlyRest = CanSold + prices[i];
            CanSold = max(CanSold, CanBuy - prices[i]);
            CanBuy = max(CanBuy, prevOnlyRest);
        }
        return max(OnlyRest, CanBuy);
    }
};

int main(){
    Solution sol;
}
