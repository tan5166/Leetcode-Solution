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
    void dfs(vector<int>& candidates, int target, int start,  vector<int> current, vector<vector<int>>& result){
        if (target < 0){
            return;
        }
        if (target == 0){
            result.push_back(current);
            return;
        }
        for(int i = start; i < candidates.size(); i++){
            if(target - candidates[i] < 0) break;
            current.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, current, result);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, current, result);
        return result;
    }
};

int main(){
    Solution sol;
}
