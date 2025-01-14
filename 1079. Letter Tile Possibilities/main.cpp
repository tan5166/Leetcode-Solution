#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
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
    int dfs(set<char> table, int* freq){
        int result = 0;
        for(const char& elem:table){
            if (freq[elem-'A']!=0){
                freq[elem -'A']--;
                result += dfs(table, freq) + 1;
                freq[elem -'A']++;
            }
        }
        return result;
    }
    int numTilePossibilities(string t) {
        set<char> table;
        int freq[26] = {0};
        for(int i =0; i<t.length();i++){
            freq[t[i]-'A'] ++;
            table.insert(t[i]);

        }
        return dfs(table, freq);
    }
};

int main(){
    Solution sol;
}
