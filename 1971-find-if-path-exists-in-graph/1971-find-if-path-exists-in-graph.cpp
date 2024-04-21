class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<vector<int>> ans(n);
    vector<bool> vis(n,false);
    //int m=edges[0].size();
    for(int i=0;i<edges.size();i++){
        ans[edges[i][0]].push_back(edges[i][1]);
        ans[edges[i][1]].push_back(edges[i][0]);
    }
    queue<int>q;
    q.push(source);
    vis[source]=true;
    while(!q.empty()){
         int node=q.front();         
         if(vis[destination]==true){
             return true;
         }
         q.pop();
         for(auto &it:ans[node]){
             if(!vis[it]){
                 vis[it]=true;
                 q.push(it);
             }
         }

     }
    return false;
    }
};