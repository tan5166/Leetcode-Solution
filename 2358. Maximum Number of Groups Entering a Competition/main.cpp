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
    int maximumGroups(vector<int>& grades) {
        int size = grades.size();
        int left = 1;
        int right = 500;
        int result;
        while(left <= right){
            int m = left + (right - left)/2;
            if (m*(m+1)/2 > size){
                right = m - 1;
            }
            else{
                left = m + 1;
                result = m; 
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
}
