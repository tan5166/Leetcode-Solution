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
    void calcSubset(string s, vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result){
        if (current.size() == 3){
             if (current.back() + 1 >= s.length()) {
                return;
            }
            string check = "";
            check = s.substr(current[current.size()-1] + 1, s.length() - current[current.size()-1] - 1);
            if (stoi(check)>= 0 && stoi(check) <= 255 && (check[0] != '0' || check.size() > 1)){
                result.push_back(current);
            }
            return;
        }
        for(int i = index; i < nums.size(); i++){
            current.push_back(nums[i]);
            string check = "";
            if (current.size() < 2){
                check = s.substr(0, current[0]);
            }
            else{
                int start = current[current.size() - 2] + 1;
                int end = current.back();
                check = s.substr(start, end - start);
            }

            if (!check.empty() && stoi(check)>= 0 && stoi(check) <= 255 && (check[0] != '0' || check.size() == 1)){
                calcSubset(s, nums, i + 1 , current, result);
            }
            current.pop_back();
        }
    }
    vector<vector<int>> subsets(string s){
        vector<vector<int>> result;
        vector<int> nums;
        vector<int> current;
        for(int i = 0; i < s.length(); i++) nums.push_back(i);
        calcSubset(s, nums, 1, current, result);
        return result;
    }
    string insertDots(const std::string& s, const std::vector<int>& triplet) {
        string result = s; // 复制原字符串，防止修改原始数据

        // 从后往前插入，避免影响索引
        for (auto it = triplet.rbegin(); it != triplet.rend(); ++it) {
            if (*it >= 0 && *it < static_cast<int>(result.size())) {
                result.insert(*it + 1, "."); // 在索引 *it 后插入 '.'
            }
        }

        return result;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<vector<int>> com = subsets(s);
        vector<string> results;
        for (const auto& triplet : com){
            results.push_back(insertDots(s, triplet));
        }
        return results;
    }
};

int main(){
    Solution sol;
}
