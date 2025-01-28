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
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        int count = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        int j = 0;
        for(int i = 1; i <= 100000; i++){
            while(!pq.empty() && pq.top() < i){
                pq.pop();
            }
            while (j < n && events[j][0] == i){
                pq.push(events[j][1]);
                j++;
            }
            if (!pq.empty()){
                count++;
                pq.pop();
            }
        }
        return count;
    }
};

int main(){
    Solution sol;
}
