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
    bool safe(vector<vector<char>>& board, int row, int col, char num){
        for(int i = 0; i < 9; i++){
            if(board[row][i] == num){
                return false;
            }
        }
        for(int i = 0; i < 9; i++){
            if(board[i][col] == num){
                return false;
            }
        }
        int boxrow = (row / 3) * 3;
        int boxcol = (col / 3) * 3;
        for(int i = boxrow; i < boxrow + 3; i ++){
            for(int j = boxcol; j < boxcol + 3; j ++){
                if(board[i][j] == num){
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(vector<vector<char>>& board, int row, int col){
        int newrow = row;
        int newcol = col + 1;
        if(newrow == 9){
            return true;
        }
        if(newcol == 9){
            newrow = row + 1;
            newcol = 0;
        }
        if(board[row][col] != '.'){
            return dfs(board, newrow, newcol);
        }
        
        for(int i = '1'; i <= '9'; i++){
            if (safe(board, row, col, i)){
                board[row][col] = i;
                if(dfs(board, newrow, newcol)){
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0, 0);
    }
};

int main(){
    Solution sol;
}
