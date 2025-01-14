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
    int numWaterBottles(int numBottles, int numExchange) {
        int result = 0;
        int empty = 0;
        int full = numBottles;
        while(full != 0){
            result += full;
            empty += full;
            full = empty / numExchange;
            empty = empty % numExchange;
        }
        return result;
    }
};

int main(){
    Solution sol;
    cout<< sol.numWaterBottles(9,3);
}
