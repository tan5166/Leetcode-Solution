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
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int result = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    result += 4;
                    if ((i > 0) && grid[i - 1][j] == 1)
                    {
                        result--;
                    }
                    if ((i + 1 < grid.size()) && grid[i + 1][j] == 1)
                    {
                        result--;
                    }
                    if ((j > 0) && grid[i][j - 1] == 1)
                    {
                        result--;
                    }
                    if ((j + 1 < grid[i].size()) && grid[i][j + 1] == 1)
                    {
                        result--;
                    }
                }
            }
            cout << result << endl;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    sol.islandPerimeter(grid);
}