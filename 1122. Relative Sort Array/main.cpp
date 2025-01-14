#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
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
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> hm;
        for(int i = 0; i< arr2.size();i++){
            hm[arr2[i]] = i;
        }
        for(int i = 0; i< arr1.size();i++){
            if (hm.find(arr1[i]) != hm.end()) continue;
            hm[arr1[i]] = arr2.size() + arr1[i];
        }

        int n = arr1.size();
        vector<int> C(1001,0);
        for(int i = 0; i<n;i++){
            C[hm[arr1[i]]] ++;
        }
        for(int i =1; i<1001;i++){
            C[i] += C[i-1];
        }
        vector<int> result(n);
        for(int i = n-1; i>=0; i--){
            result[C[hm[arr1[i]]]-1] = arr1[i];
            C[hm[arr1[i]]] --;
        }
        return result;
    }
};

int main(){
    Solution sol;
}
