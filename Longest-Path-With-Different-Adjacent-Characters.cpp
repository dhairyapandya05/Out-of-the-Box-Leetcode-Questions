class Solution {
public:
    int result;
    int dfs(int node,int parent,unordered_map<int,vector<int>>&adj,string& s){
        int longest=0;
        int second_longest=0;

        for(auto& it:adj[node]){
            if(it==parent) continue;
            int longestpathfromnode=dfs(it,node,adj,s);
            if(s[it]==s[node]) continue;
            if(longestpathfromnode>second_longest) 
            second_longest=longestpathfromnode;

            if(second_longest>longest) 
            swap(longest,second_longest);
        }
        int koiekaacha=max(longest,second_longest)+1;
        int neechaehimilgayaanswer=longest+second_longest+1;
        int onlyroot=1;
        result=max({result,koiekaacha,neechaehimilgayaanswer,onlyroot});
        return max(onlyroot,koiekaacha);
    }
    int longestPath(vector<int>& parent, string s) {
        unordered_map<int,vector<int>>adj;
        result=0;
        int n=parent.size();

        for(int i=1;i<n;i++){
            int u=i;
            int v=parent[i];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        dfs(0,-1,adj,s); 
        return result;
    }
};