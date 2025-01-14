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
    string reversePrefix(string word, char ch) {
        int firstindex = 0;
        int lastindex = 0;
        for(int i =0 ; i<word.length(); i++){
            if(word[i] == ch){
                lastindex = i;
                break;
            }
        }
        while(firstindex < lastindex){
            char tmp = word[firstindex];
            word[firstindex] = word[lastindex];
            word[lastindex] = tmp;
            lastindex --;
            firstindex ++;
        }
        return word;
    }
};

int main(){
    Solution sol;
}
