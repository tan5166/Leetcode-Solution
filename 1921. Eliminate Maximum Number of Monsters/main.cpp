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
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int ans = 0;
        int n = dist.size();
        vector<int> div(n,0);
        for(int i = 0; i < n; i++){
            div[i] = dist[i] / speed[i];
        }
        for(int i = 0; i < n; i++){
            if(div[i]>0)
            ans++;
        }
        return ans;
    }
};

int main(){
    Solution sol;
}
