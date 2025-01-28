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
    void dfs(vector<int>& tasks, int sessionTime, int index, vector<int> session, int& result){
        if (session.size() >= result){
            return;
        }
        if (index == tasks.size()){
            result = session.size();
            return;
        }
        
        for(int i = 0; i < session.size(); i++){
            if (tasks[index] + session[i] <= sessionTime){
                session[i] += tasks[index];
                dfs(tasks, sessionTime, index + 1, session, result);
                session[i] -= tasks[index];
            }
        }
        session.push_back(tasks[index]);
        dfs(tasks, sessionTime, index + 1, session, result);
        session.pop_back();
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        int result = tasks.size();
        vector<int> session;
        dfs(tasks, sessionTime, 0, session, result);
        return result;
    }
};

int main(){
    Solution sol;
}
