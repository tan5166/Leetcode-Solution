# 1981. Minimize the Difference Between Target and Chosen Elements

## Complexity

- Time Complexity: $O(n * m)$
- Space Complexity: $O(1)$



## Idea

We use the bitset `seen` to record the sum that we have seen, $seen[i]  = 1$ if and only if we have seen the sum $i$. By this idea, we first set $seen[0]= 1$. When there is a new number, say $num$, and we want to find all of its possible sum with the previous recorded sum, we can just simply use $seen << num$. Hence, we have the following code:

````c++
int n = mat.size();
int m = mat[0].size();
bitset<70 * 70 + 1> seen;  //this is because  mat[i][j]<=70 and n <= 70, so the largest sum is 70*70.
seen[0] = 1;
for(auto& row : mat){
    bitset<70 * 70 + 1> new_seen;
    for(int num : row){
        new_seen |= (seen << num);
    }
    seen = new_seen;
}
````

After this, we start by looking around $seen[target]$ to find the number closest to it.

````C++
for(int i = 0; i<=target; i++){
    if(seen[target + i] || seen[target - i]){
        return i;
    }
}
for(int i = target + 1; i < 4901; i++){
    if(seen[target + i]) return i;
}
````



## Full Code

````C++
int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        bitset<70 * 70 + 1> seen;  //this is because  mat[i][j]<=70 and n <= 70, so the largest sum is 70*70.
        seen[0] = 1;
        for(auto& row : mat){
            bitset<70 * 70 + 1> new_seen;
            for(int num : row){
                new_seen |= (seen << num);
            }
            seen = new_seen;
        }

        for(int i = 0; i<=target; i++){
            if(seen[target + i] || seen[target - i]){
                return i;
            }
        }

        for(int i = target + 1; i < 4901; i++){
            if(seen[target + i]) return i;
        }
    }
````







