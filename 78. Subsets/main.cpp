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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans(1);

        for(int i = 0; i < nums.size(); i++){
            //insert nums[i]
            int size = ans.size();
            for(int j = 0; j<size; j++){
                vector<int> tmp = ans[j];
                tmp.push_back(nums[i]);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
}
