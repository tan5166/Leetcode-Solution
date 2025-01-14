#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string> 
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
        int size = prices.size();
        int buy = prices[0];
        int result = 0;

        for(int i=1; i<size; i++){
            if (buy > prices[i]) buy = prices[i];
            result = max(result,prices[i]-buy);
        }
        return result;
    }
};

int main(){
    Solution sol;
}
