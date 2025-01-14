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
    bool able(vector<int>& v, int days, int capac){
        int count = 1;
        int prev = 0;
        for(int i = 0; i< v.size(); i++){
            if(prev + v[i] <= capac){
                prev += v[i];
            }
            else{
                prev = v[i];
                count ++;
            }
        }
        cout <<"capacity: " <<capac<<" day: "<<count <<endl;
        return (count <= days);
    }
    int shipWithinDays(vector<int>& v, int days) {
        int left = *max_element(v.begin(), v.end());
        int right = 25000000;
        int result = left;
        while(left <= right){
            int mid = left + (right - left)/2;
            if (able(v, days, mid)){
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
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    sol.shipWithinDays(v, days);
}
