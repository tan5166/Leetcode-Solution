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
    vector<int> getRow(int rowIndex) {
        vector<int> tmp;
        for(int i =0;i<=rowIndex;i++){
            vector<int> v(i+1,1);
            if (i>=2){
                for(int j=1;j<i;j++){
                    v[j] = tmp[j-1] + tmp[j];
                }
            }
            tmp = v;
        }
        return tmp;
    }
};

int main(){
    Solution sol;
}
