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
    int fib(int n) {
        vector<int> v(n+1);
        v[0] = 0;
        v[1] = 1;
        for(int i=2; i<= n;i++){
            v[i] = v[i-1] + v[i-2];
        }
        return v[n];
    }
};

int main(){
    Solution sol;
}
