#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string> 
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
    void Merge(vector<int>& nums, int left, int mid, int right){
        vector<int> leftArray(nums.begin()+left,nums.begin()+mid + 1);
        vector<int> rightArray(nums.begin()+mid + 1,nums.begin()+right + 1);
        int i = 0;
        int j = 0;
        int k = left;
        while(i<leftArray.size() && j<rightArray.size()){
            if (leftArray[i]<= rightArray[j]){
                nums[k] = leftArray[i];
                i++;
            }
            else{
                nums[k] = rightArray[j];
                j++;
            }
            k++;
        }
        while (i<leftArray.size()){
            nums[k] = leftArray[i];
            i++;
            k++;
        }
        while (j<rightArray.size()){
            nums[k] = rightArray[j];
            j++;
            k++;
        }
    }
    void MergeSort(vector<int>& nums, int left, int right){
        if (left < right){
            int mid = left + (right - left)/2;
            MergeSort(nums, left, mid);
            MergeSort(nums, mid + 1, right);
            Merge(nums, left, mid, right);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        MergeSort(nums, 0,nums.size()-1);
        return nums;
    }
};

int main(){
    Solution sol;
}
