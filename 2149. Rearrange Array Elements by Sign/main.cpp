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
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        vector<int> r;
        for(int i = 0; i<nums.size(); i++){
            if (nums[i] >= 0){
                pos.push_back(nums[i]);
            }
            else neg.push_back(nums[i]);
        }

        for(int i = 0; i<nums.size()/2; i++){
            r.push_back(pos[i]);
            r.push_back(neg[i]);
        }
        return r;
    }
};

int main(){
    Solution sol;
}
