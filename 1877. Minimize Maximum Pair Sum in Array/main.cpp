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
    int minPairSum(vector<int>& num) {
        sort(num.begin(),num.end());
        int left = 0;
        int right = num.size() - 1;
        int max = 0;
        while (left < right){
            if (num[left] + num[right] > max){
                max = num[left] + num[right];
            }
            left ++;
            right --;
        }
        return max;
    }
};

int main(){
    Solution sol;
}
