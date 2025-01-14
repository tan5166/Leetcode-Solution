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
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n+1, 0);
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){
            freq[A[i]] ++;
            if(freq[A[i]] == 2) ans[i] ++;
            freq[B[i]] ++;
            if(freq[B[i]] == 2) ans[i] ++;
        }
        for(int i=1; i<n; i++){
            ans[i] = ans[i-1] + ans[i];
        }
        return ans;
    }
};

int main(){
    Solution sol;
}
