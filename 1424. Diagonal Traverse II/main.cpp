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

struct Compare {
    bool operator()(const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b) {
        if (get<0>(a) != get<0>(b)) {
            return get<0>(a) > get<0>(b); // 比较 a
        } else if (get<1>(a) != get<1>(b)) {
            return get<1>(a) < get<1>(b); // 比较 b
        } else if (get<2>(a) != get<2>(b)){
            return get<2>(a) < get<2>(b); // 比较 c
        }
        else
            return get<3>(a) > get<3>(b);
    }
};

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, Compare> heap;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j< nums[i].size(); j++){
                heap.push(make_tuple(i+j, i, j, nums[i][j]));
            }
        }
        vector<int> result;
        int size = heap.size();
        for(int k = 0; k< size; k++){
            tuple<int, int, int, int> a = heap.top();
            heap.pop();
            result.push_back(get<3>(a));
        }
        return result;
    }
};

// int main(){
//     Solution sol;
    
// }
int main() {
    // 创建最小堆
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Compare> minHeap;

    // 插入数据
    minHeap.push(make_tuple(2, 3, 4));
    minHeap.push(make_tuple(1, 5, 6));
    minHeap.push(make_tuple(1, 2, 7));
    minHeap.push(make_tuple(3, 1, 0));

    // 打印堆顶元素并弹出堆顶
    cout << "Elements in the min heap (in order):" << endl;
    while (!minHeap.empty()) {
        auto top = minHeap.top();
        cout << "(" << get<0>(top) << ", " << get<1>(top) << ", " << get<2>(top) << ")" << endl;
        minHeap.pop();
    }

    return 0;
}
