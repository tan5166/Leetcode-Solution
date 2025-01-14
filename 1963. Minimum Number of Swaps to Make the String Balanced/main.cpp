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
    int minSwaps(string s) {
        int n = s.length();
        int balance = 0;
        int result = 0;
        int j = n-1;
        for(int i = 0; i< n; i++){
            if(s[i] == '['){
                balance++;
            }
            if(s[i] == ']'){
                balance--;
            }
            if(balance < 0){
                while(i < j && s[i]!= '['){
                    j--;
                }
                swap(s[i],s[j]);
                result++;
                balance = 1;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
}
