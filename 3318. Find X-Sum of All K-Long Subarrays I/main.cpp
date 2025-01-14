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
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> result;
        vector<int> freq(51, 0);
        for(int i = 0; i<k; i++){
            freq[nums[i]] ++;
        }
        result.push_back(Xsum(freq, x));
        for(int n = 1; n < nums.size() - k + 1; n++){
            freq[nums[n-1]] --;
            freq[nums[n + k - 1]] ++;
            result.push_back(Xsum(freq, x));
        }
        return result;
    }
    int Xsum(vector<int> freq, int x){
        int result = 0;
        priority_queue<pair<int, int>> heap;
        for(int i = 0; i< 51; i++){
            heap.push(make_pair(freq[i], i));
        }
        for(int j = 0; j<x;j ++){
            result += heap.top().first * heap.top().second;
            heap.pop();
        }
        return result; 
    }
};

int main(){
    Solution sol;
}
