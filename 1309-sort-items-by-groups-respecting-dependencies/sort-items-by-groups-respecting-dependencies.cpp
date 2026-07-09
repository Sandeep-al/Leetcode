class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group,
                          vector<vector<int>>& beforeItems) {

        int newgroup = m;
        for (int i = 0; i < n; i++) {
            if (group[i] == -1)
                group[i] = newgroup++;
        }

        vector<vector<int>> adj(n);
        vector<vector<int>> groupadj(newgroup);

        vector<int> indegree(n, 0);
        vector<int> groupindegree(newgroup, 0);

        set<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            int currGroup = group[i];

            for (int pre : beforeItems[i]) {

                adj[pre].push_back(i);
                indegree[i]++;

                if (group[pre] != currGroup) {

                    if (st.insert({group[pre], currGroup}).second) {
                        groupadj[group[pre]].push_back(currGroup);
                        groupindegree[currGroup]++;
                    }
                }
            }
        }

        queue<int> q;
        vector<int> items_topo;

        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i);

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            items_topo.push_back(node);

            for (int nxt : adj[node]) {
                indegree[nxt]--;

                if (indegree[nxt] == 0)
                    q.push(nxt);
            }
        }

        if (items_topo.size() != n)
            return {};

        vector<int> group_topo;

        while (!q.empty())
            q.pop();

        for (int i = 0; i < newgroup; i++)
            if (groupindegree[i] == 0)
                q.push(i);

        while (!q.empty()) {

            int g = q.front();
            q.pop();

            group_topo.push_back(g);

            for (int nxt : groupadj[g]) {

                groupindegree[nxt]--;

                if (groupindegree[nxt] == 0)
                    q.push(nxt);
            }
        }

        if (group_topo.size() != newgroup)
            return {};

        unordered_map<int, vector<int>> bucket;

        for (int item : items_topo)
            bucket[group[item]].push_back(item);

        vector<int> ans;

        for (int g : group_topo) {
            for (int item : bucket[g])
                ans.push_back(item);
        }

        return ans;
    }
};