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
    int appendCharacters(string s, string t) {
        int idx = 0;
        for(int i = 0; i < s.length(); i++){
            if (t[idx] == s[i]){
                idx++;
            }
            if (idx == t.length()) break;
        }
        return t.length() - idx;
    }
};

int main(){
    Solution sol;
}
