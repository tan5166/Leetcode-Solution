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
    bool check(vector<int>& tasks, int sessionTime, int index, int sessionNum, vector<int> session){
        if (index == tasks.size()) return true;
        for(int i = 0; i < sessionNum; i++){
            if(session[i] + tasks[index] <= sessionTime){
                session[i] += tasks[index];
                if(check(tasks, sessionTime, index + 1, sessionNum, session)){
                    return true;
                }
                session[i] -= tasks[index];
            }
            if (session[i] == 0) break;
        }
        return false;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        sort(tasks.rbegin(),tasks.rend());
        int n = tasks.size();
        vector<int> session(n, 0);
        int low = 1;
        int high = n;
        while(low < high){
            int mid = low + (high - low) /2 ;
            if (check(tasks, sessionTime, 0, mid, session)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};

int main(){
    Solution sol;
}
