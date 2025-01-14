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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> diff(n); 
        for(int i = 0; i< n; i++){
            diff[i] = gas[i] - cost[i];
        }
        vector<pair<int, int>> large;
        int sum = 0;
        bool flag = false;
        int index = INT_MAX;
        for(int i = 0; i < n; i++){
            if (diff[i] > 0){
                index = min(i,index);
                sum += diff[i];
                flag = true;
            }
            else{
                if (flag){
                    large.push_back(make_pair(index,sum));
                }
                index = INT_MAX;
                sum = 0;
                flag = false;
            }
        }

        int maxSecond = large[0].second;
        int index = large[0].first;

        for (const auto& p : large) {
            if (p.second > maxSecond) {
                maxSecond = p.second;
                index = p.first;
            }
        }
        
        return index;
    }
};

int main(){
    Solution sol;
}
