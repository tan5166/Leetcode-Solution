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
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> s;
        s.push_back(words[0]);
        int flag = groups[0];
        for(int i=1; i<words.size();i++){
            if (groups[i] != flag){
                s.push_back(words[i]);
                flag = groups[i];
            }
        }
        return s;
    }
};

int main(){
    Solution sol;
}
