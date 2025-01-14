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
    struct sort_pred {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        }
    };
    int largestValsFromLabels(vector<int>& value, vector<int>& label, int num, int limit) {
        vector<pair<int, int>> p;
        unordered_map<int, int> map;

        for(int i=0 ; i<value.size(); i++){
            p.push_back(make_pair(value[i],label[i]));
        }
        std::sort(p.begin(), p.end(), sort_pred());
        
        int result = 0;
        for(int i = 0; i<p.size(); i++){
            if(map[p[i].second] < limit){
                result += p[i].first;
                map[p[i].second]++;
                num--;
            }
            if (num == 0) break;
        }
        return result;
    }
};

int main(){
    Solution sol;
}
