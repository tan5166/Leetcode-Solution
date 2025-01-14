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
    vector<int> partitionLabels(string s) {
        vector<int> result;
        unordered_map<char, int> map;
        for(int i=0; i<s.length(); i++){
            if(i>=map[s[i]]){
                map[s[i]] = i;
            }
        }
        int end = map[s[0]];
        int size = 0;
        for(int i = 0; i< s.length(); i++){
            size ++;
            if(map[s[i]]>end){
                end = map[s[i]];
            }

            if (i == end){
                result.push_back(size);
                size = 0;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
}
