#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
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
    int minSteps(string s, string t) {
        vector<int> fs(26,0);
        vector<int> ft(26,0);
        int result = 0;
        for(int i = 0; i < s.length();i++){
            fs[s[i]-'a'] ++;
            ft[t[i]-'a'] ++;
        }
        for(int i = 0; i < 26 ;i++){
            if (fs[i]> ft[i])
                result += abs(fs[i] - ft[i]);
        }

        // cout << "fs: ";
        // for(int i = 0; i < 26 ;i++){
        //     cout << fs[i] << " ";
        // }
        // cout << endl;

        // cout << "ft: ";
        // for(int i = 0; i < 26 ;i++){
        //     cout << ft[i] << " ";
        // }
        // cout << endl;
        return result;
    }
};

int main(){
    Solution sol;
    cout << sol.minSteps("bab","aba");
}
