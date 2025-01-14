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
    int tribonacci(int n) {
        int t0 = 0;
        int t1= 1;
        int t2 = 1;
        int result = (n==0)? 0:1;
        
        for (int i =3; i<=n; i++){
            result = t0+t1+t2;
            t0 = t1;
            t1 = t2;
            t2 = result;
        }
        return result;
    }
};

int main(){
    Solution sol;
}
