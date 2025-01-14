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
    int minOperations(vector<int>& nums, int k) {
        vector<int> v(20,0);
        int result = 0;
        for(int i= 0; i<20;i++){
            v[i] = (k >> i) & 1;
        }
        for (int i=0; i<20;i++){
            int one = 0; //count the bit of 1
            for(int j=0;j<nums.size();j++){
                if ((nums[j] >> i) & 1) one++;
            }
            if(v[i] == 0) result += (one%2)?0:1;
            else result += (one%2)?1:0;
        }
        return result;
    }
};

int main(){
    Solution sol;
}
