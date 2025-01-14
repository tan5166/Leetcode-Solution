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
    int mySqrt(int x) {
        if (x == 0) return 0;
        int left = 1;
        int right = x;
        while (left <= right){
            cout << "left: " << left << endl;
            cout << "right: " << right << endl;
            int mid = left + (right - left)/2;
            if (mid == x/mid){
                return mid;
            }
            else if (mid > x/mid){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return right;
    }
};

int main(){
    Solution sol;
}
