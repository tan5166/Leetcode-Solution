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
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> C(1001,0);
        for(int i=0; i<n;i++){
            C[citations[i]] ++;
        }
        for(int j=1; j<1001;j++){
            C[j] += C[j-1];
        }
        vector<int> B(citations);
        for(int i=n-1; i>=0;i--){
            B[C[citations[i]]-1] = citations[i];
            C[citations[i]] --;
        }
        int result = 0;
        for(int j = n-1; j>=0; j--){
            if (B[j]<n-j) break;
            result ++;
        }
        return result;
    }
};

int main(){
    Solution sol;
}
