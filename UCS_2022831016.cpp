#include <iostream>
#include <vector>
#include <queue>
#include <climits>  
using namespace std;
int uniformCostSearch(
    int start,
    int goal,
    vector<vector<pair<int,int>>>& graph
) {
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<int> dist(graph.size(), INT_MAX);

    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (node == goal)
            return cost;

        if (cost > dist[node])
            continue;

        for (auto edge : graph[node]) {
            int nextNode = edge.first;
            int edgeCost = edge.second;
            int newCost = cost + edgeCost;

            if (newCost < dist[nextNode]) {
                dist[nextNode] = newCost;
                pq.push({newCost, nextNode});
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;
    vector<vector<pair<int,int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u].push_back({v, cost});
    }

    int start, goal;
    cin >> start >> goal;

    int result = uniformCostSearch(start, goal, graph);
    cout << result << "\n";

    return 0;
}
