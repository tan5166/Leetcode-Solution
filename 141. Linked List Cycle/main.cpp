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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(slow->next && fast->next->next){
            if(slow == fast){
                return true;
            }
            slow = slow ->next;
            fast = fast->next->next;
        }
        return false;
    }
};

int main(){
    Solution sol;
}
