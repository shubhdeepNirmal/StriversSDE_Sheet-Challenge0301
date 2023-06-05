#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
   unordered_map<int,set<int>>adj;
   for(auto it: edges)
   {
       adj[it.first].insert(it.second);
       adj[it.second].insert(it.first);
   }

   vector<int> ans;
   
   unordered_map<int,bool> visited;

   //since disconnected
for(int i=0;i<vertex;i++)
{
    if(!visited[i])
   {
       queue<int>q;
       q.push(i);
       
       while(!q.empty())
       {
           int ele= q.front();
           q.pop();
           if(visited[ele])
            continue;
            
            visited[ele]= true;
            ans.push_back(ele);

            for(auto it: adj[ele])
            {
                if(!visited[it])
                 q.push(it);
            }
       }
   }
   
}
   
   return ans;
}
