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
    int dfs(vector<int>& cookies, int k, int i, vector<int> child, int zeroCount){
        if (cookies.size() - i < zeroCount){
            return INT_MAX;
        }
        if (i == cookies.size()){
            return *max_element(child.begin(),child.end());
        }

        int ans = INT_MAX;
        for(int j = 0; j < k; j++){
            zeroCount -= child[j] == 0 ? 1 : 0;
            child[j] += cookies[i];
            ans = min(dfs(cookies, k, i+1, child, zeroCount), ans);
            child[j] -= cookies[i];
            zeroCount += child[j] == 0 ? 1 : 0;
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> child(k,0);
        return dfs(cookies, k, 0, child, k);
    }
};

int main(){
    Solution sol;
}
