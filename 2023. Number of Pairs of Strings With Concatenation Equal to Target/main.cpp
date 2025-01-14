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
    int numOfPairs(vector<string>& nums, string target) {
        int result = 0;
        int l = target.length();
        for(int i = 0; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                if (j == i || nums[i].length() + nums[j].length() != l) continue;
                if (nums[i] + nums[j] == target) result++;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
}
