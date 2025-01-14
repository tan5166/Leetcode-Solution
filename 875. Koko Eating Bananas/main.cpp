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
    bool CanEatAll(vector<int>& piles, int h, double speed){
        int usedhour = 0;
        for(int i = 0; i< piles.size(); i++){
            usedhour += ceil(piles[i]/speed);
        }
        return (usedhour <= h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int result = 1;
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());
        while(left <= right){
            int mid = left + (right - left)/2;
            if (CanEatAll(piles, h, mid)){
                result = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
}
