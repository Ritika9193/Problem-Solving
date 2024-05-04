class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int i,vector<int>& vis,stack<int>&st, vector<vector<int>>& adj){
	    vis[i]=1;
	    for(auto it:adj[i]){
	        if(vis[it]==0){
	            dfs(it,vis,st,adj);
	        }
	    }
	    st.push(i);
	}
	void dfs2(int i,vector<int>& vis, vector<vector<int>>&adjt){
	    vis[i]=1;
	    for(auto it:adjt[i]){
	        if(vis[it]==0){
	            dfs2(it,vis,adjt);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
       vector<int>vis(V,0);
       stack<int>st;
       for(int i=0;i<V;i++){
           if(vis[i]==0){
              dfs(i,vis,st,adj);
           }
       }
       
       vector<vector<int>>adjt(V);
       for(int i=0;i<V;i++){
           vis[i]=0;
           for(auto it :adj[i]){
               adjt[it].push_back(i);
           }
       }
       int scc=0;
       while(!st.empty()){
           int node=st.top();
           st.pop();
           if(vis[node]==0){
               scc++;
               dfs2(node,vis,adjt);
           }
       }
       return scc;
    }
};