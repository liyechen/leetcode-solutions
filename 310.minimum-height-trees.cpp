/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
class Solution {

    typedef vector<vector<int>> graph;

    // buildGraph from prerequisites
    graph buildGraph(int n, const graph& prerequisites) {
        graph g(n);
        for (const auto& p : prerequisites) {
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        return g;
    }

    vector<int> traverseGraph(int n, const graph& g) {
        if (n == 1) return { 0 };
        vector<int> ans;

        int degrees[n] = { 0 };
        // init degrees of each node
        for (int i = 0; i < n; i++) {
            degrees[i] = g[i].size();
        }

        bool marked[n] = { false };
        while(true) {
            bool find = false;
            unordered_set<int> nodes;
            for (int i = 0; i < n; i++) {
                if (degrees[i] == 1 && !marked[i]) {
                    marked[i] = true;
                    nodes.insert(i);
                    find = true;
                    ans.push_back(i);
                }
            }

            for (const auto& node: nodes) {
                for (const int d : g[node]) {
                    degrees[d]--;
                }
            }
            if (!find) break;
        }
        int points = 0;
        for (int i = 0; i < n; i++) {
            if (degrees[i] == 0) points++;
        }
        for (int i = 0; i < n; i++) {
            if (!marked[i]) ans.push_back(i);
        }
        int ansCount = (points == n) ? 2 : 1;
        ans.erase(ans.begin(), ans.begin() + (n - ansCount));
        return ans;
    }

public:
    // 6\n[[3,0],[3,1],[3,2],[3,4],[5,4]]
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        graph g = buildGraph(n, edges);

        // dfs to travel all the path of the graph to see
        // if there is a circle

        return traverseGraph(n, g);
    }
};
// @lc code=end

