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
    
    // GREEDY APPROACH
    // min steps to make strings equal
    
    int minSteps(string s1, string s2) {
        int size = s1.length();
        int i = 0, j = 0;
        int result = 0;
  
        while (i < size) {
            j = i;
            while (s1[j] != s2[i]) j++;
			
            while (i < j) {
                swap(s1[j], s1[j-1]);
                j--;
                result++;
            }
            i++;
        }
        return result;
    }
    
    int getMinSwaps(string num, int k) {
        string original = num;
        int i = k;
        while(k--) {
            next_permutation(num.begin(), num.end());
            cout << i-k-1 << " times :"<< num << endl;
        }
        
        return minSteps(original, num);
    }
};

int main(){
    Solution sol;
    sol.getMinSwaps("948635",64);
}
