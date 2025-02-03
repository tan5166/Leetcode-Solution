#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <bitset>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 0;
        int dec = 0;
        int incTemp = 1;
        int decTemp = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                incTemp ++;
            }
            else{
                inc = max(inc, incTemp);
                incTemp = 1;
            }
            if(nums[i] < nums[i-1]){
                decTemp ++;
            }
            else{
                dec = max(dec, decTemp);
                decTemp = 1;
            }
        }
        inc = max(inc, incTemp);
        dec = max(dec, decTemp);
        return max(inc,dec);
    }
};

int main(){
    Solution sol;
}
