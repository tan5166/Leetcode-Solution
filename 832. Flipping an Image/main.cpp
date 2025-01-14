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
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& ima) {
        for(int i = 0; i<ima.size(); i++){
            int left = 0;
            int right = ima[i].size() - 1;
            while(left < right){
                int tmp = ima[i][left];
                ima[i][left] = ima[i][right];
                ima[i][right] = tmp;
                left ++;
                right --;
            }
            for(int j=0; j< ima[i].size(); j++){
                ima[i][j] = 1 - ima[i][j];
            }
        }
        return ima;
    }
};

int main(){
    Solution sol;
}
