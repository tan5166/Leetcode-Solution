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
    // KMP algorithm
    vector<int> prefix(string needle){
        int m = needle.length();
        vector<int> pi(m, 0);
        int j = 0;
        for (int i = 1; i < m; i++){
            while(j > 0 && needle[j] != needle[i]){
                j = pi[j-1];
            }
            if (needle[j] == needle[i]){
                j++;
                pi[i] = j;
            }
        }
        return pi;
    }
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        vector<int> pi = prefix(needle);
        int j = 0; //ptr used on needle.
        for(int i = 0; i < n; i++){
            while(j>0 && haystack[i] != needle[j]){
                j = pi[j-1];
            }
            if (haystack[i] == needle[j]){
                j++;
            }
            if(j == m){
                return i-m+1;
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
}
