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
        int n = nums.size();
        vector<int> r(n,0);
        int posI = 0;
        int negI = 1;
        for(int i =0; i<nums.size(); i++){
            if(nums[i] >=0){
                r[posI] = nums[i];
                posI +=2;
            }
            else{
                r[negI] = nums[i];
                negI +=2;
            }
        }
        return r;
    }
};

int main(){
    Solution sol;
}
