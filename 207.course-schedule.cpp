/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
    // if there is a circle in the graph
    // 4\n[[2,0],[1,0],[3,1],[3,2],[1,3]]

    typedef vector<vector<int>> graph;

    // buildGraph from prerequisites
    graph buildGraph(int numCourses, const graph& prerequisites) {
        graph g(numCourses);
        for (const auto& p : prerequisites) {
            g[p[0]].push_back(p[1]);
        }
        return g;
    }

    bool traverseGraph(int numCourses, const graph& g) {
        
        int degrees[numCourses] = { 0 };
        // init degrees of each node
        for (const auto& adj : g) {
            for (const int d : adj) {
                degrees[d]++;
            }
        }

        bool marked[numCourses] = { false };
        while(true) {
            bool find = false;
            for (int i = 0; i < numCourses; i++) {
                if (degrees[i] == 0 && !marked[i]) {
                    marked[i] = true;
                    for (const int d : g[i]) {
                        degrees[d]--;
                    }
                    find = true;
                    break;
                }
            }
            if (!find) break;
        }
        int points = 0;
        for (int i = 0; i < numCourses; i++) {
            if (degrees[i] == 0) points++;
        }
        return points == numCourses;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);

        // dfs to travel all the path of the graph to see
        // if there is a circle

        return traverseGraph(numCourses, g);
    }
};
// @lc code=end

