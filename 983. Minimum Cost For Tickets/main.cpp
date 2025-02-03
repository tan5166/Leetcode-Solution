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
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int lastDay = days[n-1];
        vector<int> dp(lastDay+1, 0);
        int i = 0;
        for(int day = 1; day <= lastDay; day++){
            if (day < days[i]) dp[day] = dp[day-1];
            else{
                dp[day] = min(dp[day-1] + costs[0], min(dp[max(0,day-7)] + costs[1], dp[max(0,day-30)] + costs[2]));
                i++;
            }
        }
        return dp[lastDay];
    }
};

int main(){
    Solution sol;
}
