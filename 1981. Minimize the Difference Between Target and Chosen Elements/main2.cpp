#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <bitset>
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
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        bitset<70 * 70 + 1> seen;  //this is because  mat[i][j]<=70 and n <= 70, so the largest sum is 70*70.
        seen[0] = 1;
        for(auto& row : mat){
            bitset<70 * 70 + 1> new_seen;
            for(int num : row){
                new_seen |= (seen << num);
            }
            seen = new_seen;
        }

        for(int i = 0; i<=target; i++){
            if(seen[target + i] || seen[target - i]){
                return i;
            }
        }

        for(int i = target + 1; i < 4901; i++){
            if(seen[target + i]) return i;
        }
        return -1;
    }
};

int main(){
    Solution sol;
}
