#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int* sort(vector<int> v){
        const int range = 10;
        int C[range + 1];
        for(int i = 0; i<range + 1; i++){
            C[i] = 0;
        }
        int n = v.size();
        for (int j =0; j<n; j++){
            C[v[j]] += 1;
        }
        for (int i=1; i<range + 1; i++){
            C[i] += C[i-1];
        }

        int* result = new int[n];
        for (int i = n-1; i>=0; i--){
            result[C[v[i]]-1] = v[i];
            C[v[i]] = C[v[i]] -1;
        }

        return result;
    }

    int heightChecker(vector<int>& heights) {
        vector<int> v(heights);
        int* sortedH = sort(heights);
        int result = 0;
        for (int i=0; i<v.size();i++){
            if (v[i] != sortedH[i]) result++;
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> v = {5,2,4,1,4,9,10};
    int* p = sol.sort(v);
    for (int i=0; i<v.size();i++){
        cout<< p[i] << " ";
    }
}