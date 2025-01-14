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
        int rol = grid.size();
        int result = 0;
        int end = grid[0].size() - 1;
        for(int i = 0; i<rol; i++){
            int mid;
            int start = 0;
            while (start <= end){
                mid = start + (end-start)/2;
                if (grid[i][mid]>=0) start = mid + 1;
                else{
                    end = mid - 1;
                }
            }
            result += grid[0].size() - start;
            end = start - 1;
        }
        return result;
    }
};

int main(){
    Solution sol;
}
