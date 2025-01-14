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
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargestHelper(nums, 0, nums.size()-1, k);
    }

    int findKthLargestHelper(vector<int>& nums, int start, int end, int k) {
        int l = partition(nums, start, end);
        int leftcount = l - start + 1; //include l
        if (leftcount == k){
            return nums[l];
        }
        else if (leftcount < k){
            return findKthLargestHelper(nums, l + 1, end, k - leftcount);
        }
        else{
            return findKthLargestHelper(nums, start, l - 1, k);
        }
    }

    int partition(vector<int>& nums, int start, int end){  //included start and end
        int pivot = nums[start];
        int i = start;
        for(int j = start; j <= end; j++){
            if(nums[j] >= pivot){
                int tmp = nums[j];
                nums[j] = nums[i]; //swap nums[j] and nums[i]
                nums[i] = tmp;
                i++;
            }
        }
        int tmp = nums[end];
        nums[end] = nums[i]; //swap nums[end] and nums[i]
        nums[i] = tmp;
        return i;
    }
};

int main(){
    Solution sol;
}
