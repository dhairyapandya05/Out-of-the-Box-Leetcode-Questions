class Solution {
public:
    int N;
    int resultfromroot = 0;
    vector<int> childNodesCount;
    int dfs(int currNode, int depth, int parentNode,
            unordered_map<int, vector<int>>& mp) {
        int totalChildNode = 1;
        resultfromroot += depth;
        for (auto it : mp[currNode]) {
            if (it != parentNode) {
                totalChildNode += dfs(it, depth + 1, currNode, mp);
            }
        }
        return childNodesCount[currNode] = totalChildNode;
    }

    void dfsResult(int node, int parent, unordered_map<int, vector<int>>& mp,
                   vector<int>& result) {
        for (auto it : mp[node]) {
            if (it != parent) {
                result[it] = result[node] - childNodesCount[it] +(N - childNodesCount[it]);
                dfsResult(it, node, mp, result);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        resultfromroot = 0;
        unordered_map<int, vector<int>> mp;
        childNodesCount.resize(n, 0);
        for (auto it : edges) {
            mp[it[1]].push_back(it[0]);
            mp[it[0]].push_back(it[1]);
        }
        childNodesCount[0] = dfs(0, 0, -1, mp);
        vector<int>result (n,0);
        result[0] = resultfromroot;
        dfsResult(0, -1, mp, result);
        return result;
    }
};