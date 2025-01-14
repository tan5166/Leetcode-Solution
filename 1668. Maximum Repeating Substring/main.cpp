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
    int maxRepeating(string sequence, string word) {
        int leng = sequence.length();
        int cor = 0;
        int tmp = 0;
        int result = 0;
        for (int i=0; i<leng;i++){
            if (word[cor] == sequence[i]){
                cor ++;
            }
            else{
                cor = 0;
                tmp = 0;
            }
            if (cor == word.length()){
                tmp ++;
                result = max(result,tmp);
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
}
