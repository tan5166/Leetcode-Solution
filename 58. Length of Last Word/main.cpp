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
    int lengthOfLastWord(string s) {
        int n = s.length();
        int first_flag = true;
        int first = n - 1;
        int last = 0;
        for(int i = n-1; i>=0; i--){
            if(first_flag && s[i] != ' '){
                first = i;
                first_flag = false;
            }
            if(!first_flag && s[i] == ' '){
                last = i;
                break;
            }
        }
        return first - last;
    }
};

int main(){
    Solution sol;
}
