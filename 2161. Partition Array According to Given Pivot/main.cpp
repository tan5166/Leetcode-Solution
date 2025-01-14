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
    vector<int> pivotArray(vector<int>& nums, int p) {
        int less = 0;
        int equal = 0;
        int great = 0;
        for(int i = 0; i<nums.size(); i++){
            if (nums[i] < p){
                equal++;
            }
            if (nums[i] <= p){
                great++;
            }
        }

        vector<int> r(nums.size(), 0);

        for(int i = 0; i<nums.size(); i++){
            if (nums[i] < p){
                r[less] = nums[i];
                less ++;
            }
            else if (nums[i] > p){
                r[great] = nums[i];
                great++;
            }
            else{
                r[equal] = nums[i];
                equal++;
            }
        }
        return r;
    }
};

int main(){
    Solution sol;
}
