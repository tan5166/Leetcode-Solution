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
    int climbStairs(int n) {
        vector<int> v(n+1,1);
        v[1] = 2;
        for(int i=1; i<n-1; i++){
            v[i+1] = v[i] + v[i-1];
        }
        return v[n-1];
    }
};

int main(){
    Solution sol;
}
