#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
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
    int twoEggDrop(int n) {
        //watch https://www.youtube.com/watch?v=NGtt7GJ1uiM&ab_channel=TED-Ed
        return ceil((-1 + sqrt(1+8*n))/2);
    }
};

int main(){
    Solution sol;
}
