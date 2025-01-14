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
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) 
            count[num]++;

        int ans = 0;
        for (int num : nums) {
            if (count.find(num + 1) != count.end())
                ans = max(ans, count[num] + count[num + 1]);
            if (count.find(num - 1) != count.end())
                ans = max(ans, count[num] + count[num - 1]);
            
        }  
        return ans;
    }
};

int main(){
    Solution sol;
}
