// LeetCode-style solution for the problem: Modify Graph Edge Weights to Reach Target
class Solution {
public:
    const int LARGEVAL = 2e9; // Placeholder for unassigned edges (acts like 'infinity')

    // Helper function to compute shortest distance from source to destination using Dijkstra's algorithm
    long long dijkstra(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        unordered_map<int, vector<pair<int, int>>> mp;
        
        // Build adjacency list, ignoring edges with weight -1 for now
        for (auto& edge : edges) {
            int from = edge[0], to = edge[1], cost = edge[2];
            if (cost == -1) continue;
            mp[from].push_back({to, cost});
            mp[to].push_back({from, cost});
        }

        // Distance vector initialized to a very large number
        vector<long long> dist(n, LARGEVAL);
        dist[source] = 0;

        // Min-heap to get the node with the smallest distance
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, source});
        vector<bool> visited(n, false);

        // Standard Dijkstra's loop
        while (!pq.empty()) {
            auto [currCost, node] = pq.top(); pq.pop();
            if (visited[node]) continue;
            visited[node] = true;

            // Relaxation step
            for (auto [adj, w] : mp[node]) {
                if (currCost + w < dist[adj]) {
                    dist[adj] = currCost + w;
                    pq.push({dist[adj], adj});
                }
            }
        }

        return dist[destination];
    }

    // Main function to modify edges and try to make the shortest path == target
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        // First, calculate the shortest path with current known edges
        long long initialDist = dijkstra(n, edges, source, destination, target);

        // If the initial shortest path is already shorter than the target, not possible to make up the difference
        if (initialDist < target) return {};

        // If it already equals target, just assign LARGEVAL to all -1 weights to avoid breaking the path
        if (initialDist == target) {
            for (auto& edge : edges) {
                if (edge[2] == -1) edge[2] = LARGEVAL;
            }
            return edges;
        }

        // Now we try to adjust one of the -1 edges to make the distance exactly target
        bool found = false;

        for (auto& edge : edges) {
            if (edge[2] == -1) {
                // Temporarily set to 1 (minimum possible weight)
                edge[2] = (found == false) ? 1 : LARGEVAL;

                if (!found) {
                    long long minDist = dijkstra(n, edges, source, destination, target);
                    
                    // If the path with this edge as 1 gets us close enough to adjust, do so
                    if (minDist <= target) {
                        found = true;
                        // Increase the weight to bridge the gap between minDist and target
                        edge[2] += (int)(target - minDist);
                    }
                }
            }
        }

        // If no such adjustment was found, it's impossible
        if (!found) return {};

        return edges;
    }
};
