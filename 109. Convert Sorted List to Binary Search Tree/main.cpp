#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <stack>
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
    void layering(int* A, int start, int end, int layer){
        if (end < start){
            return;
        }
        int mid = start+(end-start+1)/2;
        A[mid] = layer;
        layering(A, start, mid-1, layer+1);
        layering(A,mid + 1,end,layer+1);
    }

    int* countlayer(int size){
        int* A = new int[size];
        layering(A,0, size-1, 1);
        return A;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        int size = 0;
        ListNode* tmp = head;
        while(tmp){
            size++; tmp = tmp->next;
        }
        int* A = countlayer(size);

        stack<pair<TreeNode*, int>> s;
        int toplevel = INFINITY;
        int count = 0;
        TreeNode* top = nullptr;
        while (head){
            TreeNode* cur = new TreeNode(head->val);
            
            if (A[count] == toplevel - 1){
                cur->left = top;
            }
            else if (A[count] == toplevel + 1){
                top->right = cur;
            }
            else{
                if (!s.empty()){

                s.push({cur, A[count]});
            }
            
            
            if (A[count] != 1 && A[count] < toplevel){
                toplevel = A[count];
                top = cur;
            }
            else if (A[count] == 1){
                cur->left = top;
                toplevel = INFINITY;
            }

            head = head ->next;
            count++;
        }
        return top;
    }
};

void Print(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* tmp = q.front();
        if (tmp && (tmp->left || tmp->right)){
            q.emplace(tmp->left);
            q.emplace(tmp->right);
        }
        q.pop();
        if(tmp != nullptr){
            cout<< tmp->val <<" ";
        }
        else{
            cout<< "null ";
        }
    }
}


int main(){
    Solution sol;
    int size = 17;
    // vector<int> nums = {1,2,3,4,5};
    int* A = sol.countlayer(size);
    for (int i =0 ; i<size; i++){
        cout << A[i] << " ";
    }
}
