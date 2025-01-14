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
    string frequencySort(string s) {
        unordered_map<char,int> h;
        for(int i=0;i<s.length();i++){
            h[s[i]] ++;
        }
        vector<pair<int, char>> v;
        for(const auto &p: h){
            v.push_back(make_pair(p.second,p.first));
        }
        sort(v.begin(),v.end());
        string r = "";
        for(const auto &k: v){
            r +=  string(k.first, k.second);
        }
        return r;
    }
};

int main(){
    Solution sol;
}
