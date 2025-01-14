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
    int maxScore(vector<int>& cardPoints, int k) {
        int totalScore = 0;
        int n = cardPoints.size();
        for(int i = 0; i < n ; i++){
            totalScore += cardPoints[i];
        }
        int result = 0;
        int sum = 0;
        int windowLength = n-k;

        if (windowLength == 0) return totalScore;

        for(int i = 0; i < n ; i++){
            sum += cardPoints[i];
            if (i >= windowLength - 1){
                result = max(totalScore - sum, result);
                sum -= cardPoints[i-windowLength+1];
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
}
