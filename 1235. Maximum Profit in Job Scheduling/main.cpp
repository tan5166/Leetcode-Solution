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
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int, int, int>> combined;
        for (int i = 0; i < n; i++){
            combined[i] = {endTime[i], startTime[i], profit[i]};
        }
        sort(combined.begin(), combined.end());
        
        vector<int> dp(n+1, 0);
        for(int i = 0; i < n; i++){
            auto [endtime, starttime, pro] = combined[i];

            int latestNonConflictJobIndex = upper_bound(combined.begin(), combined.end() + i, starttime, [&](int time, const auto& job) -> bool {
                return time < get<0>(job);
            }) - combined.begin() - 1;

            dp[i+1] = max(dp[i], dp[latestNonConflictJobIndex + 1] + pro);

        }
        return dp[n];
    }
};

int main(){
    Solution sol;
}
