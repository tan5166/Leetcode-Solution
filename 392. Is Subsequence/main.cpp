#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string> 
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
    bool isSubsequence(string s, string t) {
        int tmp = 0;
        for(int i =0; i<t.length();i++){
            if (s[tmp]==t[i]){
                tmp++;
            }
            if(tmp == s.length()) return true;
        }
        return false;
    }
};

int main(){
    Solution sol;
}
