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
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        vector<int> result(n, 0);
        for(int i=1; i<n; i++){
            left[i] = left[i-1] + nums[i-1];
        }
        for(int i=1; i<n; i++){
            right[n-1-i] = right[n-1-(i-1)] + nums[n-1-(i-1)];
        }
        for(int i=0; i<n; i++){
            result[i] = abs(left[i] - right[i]);
        }
        return result;
    }
};

int main(){
    Solution sol;
}
