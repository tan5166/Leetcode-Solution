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

#define ll long long
#define pll pair<ll, ll>
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> graph(n);
        for(auto road: roads){
            ll u = road[0] , v = road[1], t = road[2];
            graph[v].push_back({u, t});
            graph[u].push_back({v, t});
        }
        return dijkstra(graph, n);
    }
    
    int dijkstra(vector<vector<pll>> graph, int n){
        int Mod =  1000000007;
        vector<long long> ways(n,0);
        vector<ll> d(n, LONG_MAX);

        ways[0] = 1;
        d[0] = 0;

        priority_queue<pll, vector<pll>, greater<>> Q;
        Q.push({0, 0}); // push (distance, source) into Q, Q will sort by first element
        while(!Q.empty()){
            auto [t, u] = Q.top(); Q.pop();
            if (t > d[u]) continue;

            for(auto [v, time] : graph[u]){
                if(d[v] > d[u] + time){
                    d[v] = d[u] + time;
                    Q.push({d[v], v});
                    ways[v] = ways[u];
                }
                else if(d[v] == d[u] + time){
                    ways[v] =  (ways[v] + ways[u]) % Mod;
                }
            }
        }
        return ways[n-1];
    }
};

int main(){
    Solution sol;
}
