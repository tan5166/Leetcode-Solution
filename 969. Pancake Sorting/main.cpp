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
    void flip(vector<int>& arr, int idx){
        int left = 0;
        int right = idx-1;
        while(left < right){
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            left++;
            right--;
        }
    }
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> result;
        for(int i = arr.size(); i > 0 ; i --){
            int index;
            for(int j=0; j<i ;j++){
                if (arr[j] == i){
                    index = j;
                    break;
                }
            }
            if (index == i-1) continue;
            if (index != 0){
                result.push_back(index+1);
                flip(arr, index+1);
            }
            result.push_back(i);
            flip(arr, i);
        }
        return result;
    }
};

int main(){
    Solution sol;
}
