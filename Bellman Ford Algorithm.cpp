#include <cstdio> // for freopen
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dis(V, 1e8);
        dis[src] = 0;

        for(int i = 0; i < V - 1; i++) {
            for(auto ed : edges) {
                int u = ed[0], v = ed[1], wt = ed[2];
                if(dis[u] != 1e8 && dis[u] + wt < dis[v]) {
                    dis[v] = dis[u] + wt;
                }
            }
        }

        // Check negative weight cycles
        for (auto &ed : edges) {
            int u = ed[0], v = ed[1], wt = ed[2];
            if (dis[u] != 1e8 && dis[u] + wt < dis[v]) {
                return {-1};
            }
        }

        return dis; 
    }

};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int N, m;
        cin >> N >> m;

        vector<vector<int> > edges;

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(N, edges, src);

        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}