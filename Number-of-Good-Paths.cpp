class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int u){
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u]);
    }

    void Union(int u, int v){
        int parentu=find(u);
        int parentv=find(v);
        if(parentu==parentv) return;

        if(rank[u]>rank[v]){
            parent[parentv]=parentu;
        }
        else if(rank[u]<rank[v]){
            parent[parentu]=parentv;
        }
        else{
            parent[parentu]=parentv;
            rank[parentv]++;
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int result=n;
        vector<bool> isActive(n,false);
        map<int,vector<int>> valmp;
        for(int i=0;i<n;i++){
            valmp[vals[i]].push_back(i);
        }
        unordered_map<int,vector<int>>mp;
        for(auto it:edges){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }

        for(auto nd:valmp){
            int val=nd.first;
            vector<int> nodes=nd.second;
            for(auto u:nodes){
                isActive[u]=true;
                for(int v:mp[u]){
                    if(isActive[v])
                    Union(u,v);
                }
            }
            unordered_map<int,int> parentmp; //parent, freq
            for(auto u:nodes){
                int parentofu=find(u);
                parentmp[parentofu]++;
            }
            for(auto it:parentmp){
                int count=it.second;
                result+=((count*(count-1))>>1);
            }
        }
        return result;
    }
};