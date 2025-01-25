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
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int countofNine = 0;
        for(int i = n-1; i >= 0; i--){
            if(digits[i] != 9){
                break;
            }
            countofNine++;
        }
        if (countofNine != n){
            digits[n-1-countofNine] ++;
            for(int i = n-countofNine; i < n ; i++){
                digits[i] = 0;
            }
            return digits;
        }
        else{
            vector<int> result(n+1, 0);
            result[0] = 1;
            return result;
        }
    }
};

int main(){
    Solution sol;
}
