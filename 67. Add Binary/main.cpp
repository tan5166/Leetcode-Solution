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
    string addBinary(string a, string b) {
        int n = a.length();
        int m = b.length();
        int l = max(n,m);
        bool carry = false;
        string result = "";
        
        if(n < m){
            swap(a, b);
        }

        for(int i = 0 ; i < abs(n-m); i++){
            b = '0' + b;
        }
        // cout << "a: " << a << " b: "<< b << endl;

        for(int i = l-1; i >= 0; i--){
            if(a[i] == '1' && b[i] == '1'){
                result =  (carry ? '1' : '0') + result;
                carry = true;
            }
            else if (a[i] == '1' || b[i] == '1'){
                result =  (carry ? '0' : '1') + result;
            }
            else{
                result =  (carry ? '1' : '0') + result;
                carry = false;
            }
        }

        if(carry){
            result = '1' + result;
        }
        return result;
    }
};

int main(){
    Solution sol;
}
