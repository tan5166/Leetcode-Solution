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
    vector<string> subdomainVisits(vector<string>& cp) {
        unordered_map<string, int> h;
        for(int i = 0; i<cp.size(); i++){
            int pos = cp[i].find(' ');
            int count = stoi(cp[i].substr(0, pos));
            string domain = cp[i].substr(pos+1);
            h[domain] += count;
            
            size_t dot = domain.find('.');
            while(dot != string::npos){
                string after_dot = domain.substr(dot + 1);
                h[after_dot] += count;
                dot = domain.find('.', dot+1);
            }
        }
        vector<string> result;
        for(const auto &p: h){
            result.push_back(to_string(p.second) + " " + p.first);
        }
        return result;
    }
};

int main(){
    Solution sol;
}
