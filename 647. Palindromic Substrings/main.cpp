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
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n,1));
        int count = s.length();
        int size = 2;
        while(size<=s.length()){
            for(int left = 0; left + size -1 < s.length(); left++){
                int right = left + size -1;
                if (s[left] == s[right] && dp[left+1][right-1] == 1){
                    dp[left][right] = 1;
                    count++;
                }else{
                    dp[left][right] = 0;
                }
            }
            size++;
        }
        return count;
    }
};

int main(){
    Solution sol;
}
