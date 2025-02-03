#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <bitset>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> canRob(n, 0);
        vector<int> cantRob(n, 0);
        cantRob[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            canRob[i] = max(canRob[i-1], cantRob[i-1]);
            cantRob[i] = canRob[i-1] + nums[i];
        }
        return max(canRob[n-1], cantRob[n-1]);
    }
};

int main(){
    Solution sol;
}
