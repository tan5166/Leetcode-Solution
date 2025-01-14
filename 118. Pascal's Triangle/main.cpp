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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=0; i < numRows;i++){
            vector<int> v(i+1,1);
            if (i >= 2){
                for (int j=1; j<i; j++){
                    v[j] = result[i-1][j-1] + result[i-1][j];
                }
            }
            result.push_back(v);
        }
        return result;
    }
};

int main(){
    Solution sol;
}
