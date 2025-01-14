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
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length();
        int result = 0;
        for(int i = 1; i<= n; i++){
            int one = 0;
            int zero = 0;
            for(k = 0; k < i; k++){
                if (s[k] == '1') one++;
                else zero++;
            }
            if (zero <= k || one <= 1) result++;
            
            for(int j = 1; j < n-i+1; j++){
                if (s[j-1] == '1') one--;
                else zero--;
                if (s[j+i-1] == '1') one++;
                else zero++;

                if (zero <= k || one <= k) result++;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
}
