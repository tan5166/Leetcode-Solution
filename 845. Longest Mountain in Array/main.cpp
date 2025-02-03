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
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        for(int i = 1; i < n; i++){
            if(arr[i-1] < arr[i]){
                left[i] = left[i-1] + 1;
            }
        }
        for(int i = n-2; i >= 0; i--){
            if(arr[i] > arr[i+1]){
                right[i] = right[i+1] + 1;
            }
        }
        int result = 0;
        for(int i = 0; i < n; i++){
            if(left[i] && right[i])
                result = max(result, left[i] + right[i] + 1);
        }
        return result;
    }
};

int main(){
    Solution sol;
}
