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
    long long maxPoints(vector<vector<int>> &points){
        int n = points.size();
        int m = points[0].size();
        vector<long long> prev(m);
        for(int j = 0; j < m ; j++) prev[j] = points[0][j];
        for (int i = 1; i < n; i++){
            vector<long long> left(m, 0), right(m, 0), cur(m, 0);
            left[0] = prev[0];
            right[m-1] = prev[m-1];
            for(int j = 1; j < m; j++){
                left[j] = max(left[j-1] - 1, prev[j]);
            }
            for(int j = m-2; j >= 0; j--){
                right[j] = max(right[j+1] - 1, prev[j]);
            }
            for (int j = 0; j < m; j++){
                cur[j] = points[i][j] + max(left[j], right[j]);
            }
            prev = cur;
        }
        long long ans = 0;
        for(int j = 0; j < m; j++){
            ans = max(ans, prev[j]);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
}
