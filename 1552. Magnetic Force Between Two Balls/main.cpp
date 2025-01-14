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
    bool CanPutBall(vector<int>& position, int m, int gap){
        int placed = 1;
        int prevPos =position[0];
        for(int i = 1; i< position.size() && placed < m; i++){
            if (position[i] - prevPos >= gap){
                prevPos = position[i];
                placed++;
            }
        }
        return (placed == m);
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int left = 1;
        int right = (position[position.size()- 1] - position[0])/(m-1);
        int result;
        while (left <= right){
            int mid = left + (right - left)/2;
            if (CanPutBall(position, m, mid)){
                result = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
}
