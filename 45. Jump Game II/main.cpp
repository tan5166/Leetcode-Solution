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
    int jump(vector<int>& nums) {
        int ans = 0;
        int maxReach = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if (i + nums[i] > maxReach){
                ans++;
                maxReach = i + nums[i];
            }
            if (maxReach >= n-1){
                break;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
}
