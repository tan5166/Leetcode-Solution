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
    deque<int> result;
    void dfs(TreeNode* curNode, deque<int> cur){
        if (!curNode) return;
        cur.push_front(curNode->val);
        if(!curNode->left && !curNode->right){
            if (result.empty()){
                result = cur;
            }
            else if(lexicographical_compare(cur.begin(), cur.end(), result.begin(), result.end())){
                result = cur;
            }
            return;
        }
        dfs(curNode->left, cur);
        dfs(curNode->right, cur);
    }
    string smallestFromLeaf(TreeNode* root) {
        deque<int> cur;
        dfs(root, cur);
        string s;
        for(int i = 0; i < result.size(); i++){
            s += static_cast<char>('a' + result[i]);
        }
        return s;
    }
};

int main(){
    Solution sol;
}
