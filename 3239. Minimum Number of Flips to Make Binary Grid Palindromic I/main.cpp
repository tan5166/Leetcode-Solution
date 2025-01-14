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
    int minFlips(vector<vector<int>>& grid) {
        int result1 = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i<m; i++){
            int l = 0;
            int r = n-1;
            while(l<r){
                if(grid[i][l] != grid[i][r]){
                    result1 ++;
                }
                l++;
                r--;
            }
        }

        int result2 = 0;
        for(int j = 0; j < n; j++){
            int l = 0;
            int r = m-1;
            while(l<r){
                if(grid[l][j] != grid[r][j]){
                    result2 ++;
                }
                l++;
                r--;
            }
        }
        return min(result1,result2);
    }
};

int main(){
    Solution sol;
}
