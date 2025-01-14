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
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> freq(m,0);
        for(int i=0; i<n;i++){
            if (grid[i][0] == 0){
                for(int j=0; j<m;j++){
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        freq[0] = n;
        for(int j=1; j<m ; j++){
            for(int i = 0; i<n; i++){
                freq[j] += grid[i][j];
            }
            freq[j] = max(freq[j], n-freq[j]);
        }

        int result = 0;
        for(int j=0; j<m;j++){
            result  = (result<<1) + freq[j];
        }
        return result;
    }
};

int main(){
    Solution sol;
}
