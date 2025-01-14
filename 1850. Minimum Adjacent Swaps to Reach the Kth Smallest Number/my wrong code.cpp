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
    void wondeful(string& num){
        int n = num.size();
        int index;
        for(int i = n-1; i >= 0; i--){
            if (num[i] > num[i-1]){
                index = i-1;
                break;
            }
        }
        int smallest_bigger_value = INT_MAX;
        int change_index;
        for(int i = index+1; i<n; i++){
            if(num[i]> num[index] && num[i] < smallest_bigger_value){
                smallest_bigger_value = num[i];
                change_index = i;
            }
        }
        swap(num[index],num[change_index]);
        sort(num.begin() + index + 1, num.end());
    }
    int getMinSwaps(string num, int k) {
        int result = 0;
        string tmp = num;
        for(int i=0; i<k;i++){
            wondeful(num);
            // cout << i<< " times :"<<num << endl;
        }
        for(int i =0; i< num.length();i++){
            if(tmp[i]!= num[i]){
                int j = i;
                while(tmp[j]!= num[i]){
                    j++;
                }
                for(int p = j; p>i; p--){
                    swap(tmp[p],tmp[p-1]);
                    result++;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    // sol.getMinSwaps("948635",64);
}
