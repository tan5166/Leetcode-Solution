#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
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
    void dfs(int freq[3]){
        freq[1]++;
    }
    void numTilePossibilities() {
        int freq[3] = {0};
        dfs(freq);
        for(int i = 0; i<3;i++){
            cout<< "freq " << i << ": " << freq[i] << endl;
        }
    }
};

int main(){
    Solution sol;
    sol.numTilePossibilities();
}
