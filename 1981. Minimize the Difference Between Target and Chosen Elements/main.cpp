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
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();
        
        unordered_set<int> dp = {0};
        
        for (int i = 0; i < n; i++) {
            unordered_set<int> nextDp;
            for (int num : mat[i]) {
                for (int prevSum : dp) {
                    nextDp.insert(prevSum + num);
                }
            }
            
            dp = nextDp;
        }
        
        int minDiff = INT_MAX;
        for (int sum : dp) {
            minDiff = min(minDiff, abs(sum - target));
        }
        
        return minDiff;
    }
};

int main(){
    Solution sol;
}
