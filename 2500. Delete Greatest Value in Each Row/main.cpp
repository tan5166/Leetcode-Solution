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
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<priority_queue<int>> heap(n);
        for(int i = 0; i<n ; i++){ //NM log N
            for(int j = 0; j< m; j++){
                heap[i].push(grid[i][j]);
            }
        }
        int result = 0;
        for(int j = 0; j<m ; j++){ //NM log N
            int maxi = 0;
            for(int i = 0; i< n; i++){
                maxi = max(maxi, heap[i].top());
                heap[i].pop();
            }
            cout << maxi << endl;
            result += maxi;
        }
        return result;
    }
};

int main(){
    Solution sol;
}
