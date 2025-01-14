#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map> 
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
    int countSquares(vector<vector<int>>& A) {
        int result = 0;
        for(int row=0; row<A.size();row++){
            for(int col=0; col<A[0].size();col++){
                if(A[row][col]>0 && row>0 && col>0){
                    A[row][col] = min({A[row-1][col-1], A[row][col-1],A[row-1][col]}) + 1;
                }
                result += A[row][col];
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
}
