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
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int ans1 = 0;
        int ans2 = 0;
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                ans1 = i;
                ans2 = i + 1;
            }
        }

        for (int leng = 3; leng <= n; leng++)
        {
            for (int start = 0; start + leng - 1 < n; start++)
            {
                int end = start + leng - 1;
                if (s[start] == s[end] && dp[start + 1][end - 1])
                {
                    dp[start][end] = true;
                    ans1 = start;
                    ans2 = end;
                }
            }
        }
        return s.substr(ans1, ans2 - ans1 + 1);
    }
};

int main()
{
    Solution sol;
}
