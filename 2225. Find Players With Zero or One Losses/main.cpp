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
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        unordered_map<int, int> h;
        vector<vector<int>> result(2);
        for(int i=0;i<m.size();i++){
            h[m[i][0]];
            h[m[i][1]] ++;
        }
        for(const auto &pair:h){
            if (pair.second == 0) result[0].push_back(pair.first);
            if (pair.second == 1) result[1].push_back(pair.first);
        }
        sort(result[0].begin(),result[0].end());
        sort(result[1].begin(),result[1].end());
        return result;
    }
};

int main(){
    Solution sol;
}
