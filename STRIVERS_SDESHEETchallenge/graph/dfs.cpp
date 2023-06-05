void dfs(unordered_map<int,list<int>>& adjlist,int node, vector<int> &c,unordered_map<int,bool>& vis)
{
    c.push_back(node);
    vis[node]=1;

    for(auto it: adjlist[node])
    {
        if(!vis[it])
        {
            dfs(adjlist,it,c,vis);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int,list<int>>adjlist;

    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    unordered_map<int,bool> vis;
  vector<  vector <int>> ans;

    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            vector<int> c;
            dfs(adjlist,i,c,vis);
            ans.push_back(c);
        }
    }

    return ans;
}