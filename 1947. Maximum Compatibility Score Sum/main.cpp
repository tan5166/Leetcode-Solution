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
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int ans = 0;
        int n = students.size();
        int m = students[0].size();
        vector<int> pos;
        for(int i = 0; i < n; i++) pos.push_back(i);
        do{
            int value = 0;
            for(int i = 0; i< n ; i++){
                for(int j = 0; j<m; j++)
                    value += (mentors[i][j] == students[pos[i]][j]);
            }
            ans = max(ans, value);
        }
        while (next_permutation(pos.begin(), pos.end()));
        return ans;
    }
};

int main(){
    Solution sol;
}
