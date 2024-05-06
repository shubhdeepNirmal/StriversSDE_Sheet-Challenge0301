#include <vector>
using namespace std;

class Solution {
    vector<int> ans, count, subTree;
    vector<vector<int>> graph;
    int N;

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        graph.resize(N);
        ans.resize(N);
        count.resize(N);
        subTree.resize(N);        
        
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        dfs(0, -1);
        ans[0] = subTree[0];
        dfs2(0, -1);
        return ans;
    }

    void dfs(int node, int parent) {
        for (int child : graph[node]) {
            if (child != parent) {
                dfs(child, node);
                count[node] += count[child];
                subTree[node] += subTree[child] + count[child];
            }
        }
        count[node] += 1;
    }

    void dfs2(int node, int parent) {
        for (int child : graph[node]) {
            if (child != parent) {
                ans[child] = ans[node] - count[child] + N - count[child];
                dfs2(child, node);
            }
        }
    }
};
