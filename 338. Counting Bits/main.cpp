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
    vector<int> countBits(int n) {
        vector<int> result(n+1,0);
        for(int i=1; i<n+1;i++){
            result[i] = result[i/2] + i&1;
        }
        return result;
    }
};

int main(){
    Solution sol;
}
