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
        int result = 0;
        for(int i =0; i<prices.size()-1;i++){
            if (prices[i]<prices[i+1]) result+=prices[i+1]- prices[i];
        }
        return result;
    }
};

int main(){
    Solution sol;
}
