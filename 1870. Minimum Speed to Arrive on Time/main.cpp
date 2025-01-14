#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
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
    bool Speed(vector<int>& dist, double speed, double hour){
        double result = 0;
        for(int i = 0; i < dist.size() - 1;i++){
            result += ceil(dist[i]/speed);
        }
        result += dist[dist.size() - 1]/speed;
        return (result <= hour);
    }
    int minSpeedOnTime(vector<int>& dist, double hour){
        int left = 1;
        int right = 100000;
        int answer = -1;
        while (left <= right){
            int mid = left + (right - left)/2;
            if (Speed(dist, mid, hour)){
                answer = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return answer;
    }
};

int main(){
    Solution sol;
    vector<int> v = {1,1,100000};
    sol.minSpeedOnTime(v, 2.01);
}
