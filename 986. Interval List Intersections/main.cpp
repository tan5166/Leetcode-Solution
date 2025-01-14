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
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fList, vector<vector<int>>& sList) {
        vector<vector<int>> result;
        int n = fList.size();
        int m = sList.size();
        int ptr1 = 0;
        int ptr2 = 0;
        while(ptr1<n && ptr2<m){
            if (!(sList[ptr2][0] > fList[ptr1][1] || fList[ptr1][0] > sList[ptr2][1])){
                int start = max(fList[ptr1][0], sList[ptr2][0]);
                int end = min(fList[ptr1][1], sList[ptr2][1]);
                result.push_back({start,end});
            }
            if (sList[ptr2][1]<fList[ptr1][1]){
                ptr2++;
            }else{
                ptr1++;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
}
