#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set> 
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
    void dfs(int left, int right, int n, string s, vector<string>& result){
        if (left+right == 2*n){
            result.push_back(s);
            return;
        };
        if (left<n) dfs(left+1, right, n, s + "(", result);
        if (right<left) dfs(left, right+1, n, s + ")", result);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        dfs(0, 0, n, "", result);
        return result;
    }
};

int main(){
    Solution sol;
}
