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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* first = new ListNode(0, head);
        ListNode* prev = first;
        ListNode* cur = head;
        while(cur != nullptr){
            if (cur->val == val){
                prev -> next = cur->next;
                cur = prev->next;
            }
            else{
                prev = prev->next;
                cur = cur ->next;
            }
        }
        return first->next;
    }
};

int main(){
    Solution sol;
}
