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
    int nthUglyNumber(int n) {
        vector<int> dp(n , 0);
        dp[0] = 1;
        int m2 = 0;
        int m3 = 0;
        int m5 = 0;
        for(int i = 1; i < n; i++){
            dp[i] = min(dp[m2] * 2, min(dp[m3] * 3, dp[m5] * 5));
            if(dp[i] == dp[m2] * 2) m2++;
            if(dp[i] == dp[m3] * 3) m3++;
            if(dp[i] == dp[m5] * 5) m5++;
        }
        return dp[n-1];
    }
};

int main(){
    Solution sol;
}
