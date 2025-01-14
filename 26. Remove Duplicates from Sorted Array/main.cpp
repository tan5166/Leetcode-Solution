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
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int unique = 1;
        for(int i = 1; i < n; i++){
            if (nums[i] != nums[i-1]){
                nums[unique] = nums[i];
                unique++;
            }
        }
        return unique;
    }
};

int main(){
    Solution sol;
}
