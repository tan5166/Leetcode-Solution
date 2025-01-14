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
    int pairSum(ListNode* head) {
        int size = 0;
        ListNode* tmp = head;
        while(tmp != nullptr){
            size ++;
            tmp = tmp->next;
        }
        int half = size/2;
        
        ListNode* current = head;
        while(half != 0){
            tmp = tmp->next;
            half --;
        }
        ListNode* prev = nullptr;

        while(current != nullptr){
            ListNode* nextnode = current->next;
            current->next = prev;
            prev = current;
            current = nextnode;
        }

        int maxi = 0;
        while(prev != nullptr){
            maxi = max(prev->val + head->val, maxi);
            prev = prev->next;
            head = head->next;
        }
        return maxi;
    }
};

int main(){
    Solution sol;
}
