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
    bool alphanumeric(string s, int index){
        return (s[index] >= 'a' && s[index] <= 'z') || (s[index] >= '0' && s[index] <= '9');
    }

    bool isPalindrome(string s) {
        int n = s.length();

        // translate "A" to 'a', ..., 'Z' to 'z'.
        for(int i = 0; i < n; i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] = s[i] + 32;
            }
        }
        
        int left = 0;
        int right = n - 1;
        while(left <= right){
            while(left < n - 1 && !alphanumeric(s, left)){
                left ++;
            }
            while(right > 0 && !alphanumeric(s, right)){
                right --;
            }
            if((s[left] != s[right]) && alphanumeric(s, left)){
                return false;
            }
            left ++;
            right--;
        }
        return true;
    }
};

int main(){
    Solution sol;
}
