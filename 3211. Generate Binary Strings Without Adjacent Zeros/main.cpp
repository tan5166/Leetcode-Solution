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
    void dfs(string s, int n, vector<string>& v){
        if (s.length() == n){
            v.push_back(s);
            return;
        }
        if (s.length() == 0) dfs(s+"0",n,v);
        else if (s[s.length() -1] == '1') dfs(s + "0", n, v);
        dfs(s + "1", n, v);
        return;
    }
    vector<string> validStrings(int n) {
        vector<string> v;
        dfs("", n, v);
        return v;
    }
};

int main(){
    Solution sol;
}
