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
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int maxCharFreq[26] = {0};
        int tmpCharFreq[26] = {0};
        int n = words1.size();
        int m = words2.size();
        for(int i = 0; i < m; i++){
            memset(tmpCharFreq, 0, sizeof(tmpCharFreq));
            for(int j = 0; j < words2[i].length(); j++){
                tmpCharFreq[words2[i][j] - 'a']++;
            }
            for(int j = 0; j<26; j++){
                maxCharFreq[j] = max(maxCharFreq[j], tmpCharFreq[j]);
            }
        }
        vector<string> result;
        for(int i = 0; i < n; i++){
            memset(tmpCharFreq, 0, sizeof(tmpCharFreq));
            for(int j = 0; j < words1[i].length(); j++){
                tmpCharFreq[words1[i][j] - 'a']++;
            }
            bool flag = true;
            for(int j = 0; j < 26; j++){
                if (tmpCharFreq[j] < maxCharFreq[j]){
                    flag = false;
                    break;
                }
            }
            if (flag) result.push_back(words1[i]);
        }
        return result;
    }
};

int main(){
    Solution sol;
}
