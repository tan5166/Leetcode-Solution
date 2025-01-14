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
    int minTimeToType(string word) {
        int n = word.length();
        int ans = n;
        char prev = 'a';
        for(int i = 0; i < n; i++){
            int tmp = abs(word[i] - prev);
            ans += min(tmp, 26-tmp);
            prev = word[i];
        }
    }
};

int main(){
    Solution sol;
}
