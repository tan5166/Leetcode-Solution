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
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int col = n-1;
        int row = 0;
        int result = 0;
        while(row < m && col>=0){
            if(grid[row][col] < 0){
                result += m - row;
                col--;
            }
            else{
                row++;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
}
