// 1. BFS
// 40ms 23.47%, 11.6MB 100.00%.
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = BuildGraph(numCourses, prerequisites);

        vector<int> indegrees = ComputeIndegrees(g);

        for (int i = 0; i < numCourses; i++) {
            // Find a node with 0 indegree.
            // Because if the graph is a uncycled graph, there must be a node that the indegree is 0.
            int j = 0;
            for (; j < numCourses; j++) {
                if (indegrees[j] == 0) {
                    break;
                }
            }
            if (j == numCourses) {
                return false;
            }
            else {
                indegrees[j]--;    // If the node is like: 0 <- 1 <- 2, the node 1's indegree is 0. We set this node as -1 to prevent from visiting it again.
                // Reduce the pointing nodes indegrees.
                for (int v : g[j]) {
                    indegrees[v]--;
                }
            }
        }

        return true;
    }

private:
    typedef vector<vector<int>> graph;

    // Build the graph in adjacent graph way.
    graph BuildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        graph g(numCourses);

        for (auto pair : prerequisites) {
            if (pair.size() != 2) {
                cout << "input pair error!" << endl;

                exit(1);
            }

            g[pair[1]].push_back(pair[0]);
        }

        return g;
    }

    // Compute every node's indegrees
    vector<int> ComputeIndegrees(graph& g) {
        vector<int> degrees(g.size(), 0);

        for (auto adj : g) {
            for (int v : adj) {
                degrees[v]++;
            }
        }

        return degrees;
    }
};


// 2. DFS
// 28ms 42.54%, 12.4MB 100.00.
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = BuildGraph(numCourses, prerequisites);

        vector<bool> todo(numCourses, false), done(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            // If this node is not marked as done and it has a cycle, return false.
            if (done[i] == false && Acyclic(g, todo, done, i) == false) {
                return false;
            }
        }

        return true;
    }

private:
    using graph = vector<vector<int>>;

    // Build the graph in adjacent graph way.
    graph BuildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        graph g(numCourses);

        for (auto pair : prerequisites) {
            if (pair.size() != 2) {
                cout << "input pair error!" << endl;

                exit(1);
            }

            g[pair[1]].push_back(pair[0]);
        }

        return g;
    }

    // Start from a node, recursively check whether there is a cycle or not.
    // todo: is a temporary mark to mark the route.
    // done: is a permananet mark to mark the node that has no cycle.
    bool Acyclic(graph& g, vector<bool>& todo, vector<bool>& done, int node) {
        if (todo[node] == true) {
            return false;
        }
        if (done[node] == true) {
            return true;
        }

        todo[node] = true;
        done[node] = true;
        for (int v : g[node]) {
            if (Acyclic(g, todo, done, v) == false) {
                return false;
            }
        }
        todo[node] = false;

        return true;
    }
};