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

class CustomFunction {
public:
    // Returns f(x, y) for any given positive integers x and y.
    // Note that f(x, y) is increasing with respect to both x and y.
    // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
    int f(int x, int y);
};

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> result;
        int upp = 1000;

        for(int x = 1; x<1000; x++){
            int left = 1;
            int right = upp;
            while(left <= right){
                int mid = left + (right - left)/2;
                if (customfunction.f(x,mid) > z){
                    right = mid - 1;
                }
                else if (customfunction.f(x,mid) < z){
                    left = mid + 1;
                }
                else{
                    vector<int> v = {x, mid};
                    result.push_back(v);
                    upp = mid - 1;
                    break;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
}
