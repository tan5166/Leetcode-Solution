#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <stdio.h>
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
    void calcSubset(vector<int>& A, vector<int> subset, int index, vector<vector<int>>& result){
        result.push_back(subset);
        // for(int i = index; i < A.size(); i++){
            subset.push_back(A[index]);
            calcSubset(A, subset, index+1, result);
            subset.pop_back();
            calcSubset(A, subset, index+1, result);
        // }
    }
    vector<vector<int>> subsets(vector<int>& A){
        vector<int> subset;
        vector<vector<int>> result;
        int index = 0;
        calcSubset(A, subset, index, result);
        return result;
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> all = subsets(nums);
        int result = 0;
        for(int i = 0; i< all.size(); i++){
            int sum = 0;
            for(int j = 0; j < all[i].size(); j++){
                sum ^= all[i][j];
            }
            result += sum;
        }
        return result;
    }
};

int main(){
    Solution sol;
}
