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
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        for (int row = 0; row < n; row++)
        {
            if (board[row][0] == 'O')
            {
                dfs(row, 0, board);
            }
            if (board[row][m - 1] == 'O')
            {
                dfs(row, 0, board);
            }
        }

        for (int col = 0; col < m; col++)
        {
            if (board[0][col] == 'O')
            {
                dfs(0, col, board);
            }
            if (board[n - 1][col] == 'O')
            {
                dfs(n - 1, col, board);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == '1')
                    board[i][j] = 'O';
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    void dfs(int i, int j, vector<vector<char>> &board)
    {
        if (board[i][j] == 'O')
        {
            board[i][j] = '1';
            if (i > 0 && board[i - 1][j] == 'O')
                dfs(i - 1, j, board);
            if (j > 0 && board[i][j - 1] == 'O')
                dfs(i, j - 1, board);
            if (i + 1 < board.size() && board[i + 1][j] == 'O')
                dfs(i + 1, j, board);
            if (j + 1 < board[i].size() && board[i][j + 1] == 'O')
                dfs(i, j + 1, board);
        }
    }
};

int main()
{
    Solution sol;
}
