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
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        vector<long long> dp(n+1, 0);
        int j = 0;
        for(int i = 1; i <= n; i++){
            dp[i] = max(dp[i], dp[i-1]);
            while(j <rides.size() && rides[j][0] == i){
                dp[rides[j][1]] = max(dp[rides[j][1]], dp[i] + rides[j][2] + rides[j][1] - rides[j][0]);
                j++;
            }
        }
        return dp[n];
    }
};

int main(){
    Solution sol;
}
