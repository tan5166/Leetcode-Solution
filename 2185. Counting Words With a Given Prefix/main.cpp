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
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int result = 0;
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < pref.size(); j++){
                count ++;
                if (words[i][j] != pref[j]){
                    break;
                }
            }
            if (count == pref.size()) result++;
        }
        return result;
    }
};

int main(){
    Solution sol;
}
