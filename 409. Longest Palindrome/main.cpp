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
    int longestPalindrome(string s) {
        unordered_map<char, int> h;
        int n = s.length();
        for(int i = 0; i < n; i++){
            h[s[i]] ++;
        }
        int ans = 0;
        int maxi = 0;
        bool flag = true;
        for (const auto& p : h) {
            if (p.second % 2 == 0) ans += p.second;
            if (flag && p.first %2 == 1){
                maxi = max(p.first, maxi);
                flag = false;
            }
        }
        ans += maxi;
        return ans;
    }
};

int main(){
    Solution sol;
}
