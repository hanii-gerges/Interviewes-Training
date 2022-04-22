#pragma ide diagnostic ignored "cert-err58-cpp"
#include <bits/stdc++.h>
#define ll long long int
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define omar main
#define print(x)cout << x << endl;
#define printArray(x) for (auto i:x){cout << i << ' ';}cout<<endl;
#define arrayIn(x, size) for (int i = 0; i < size; ++i) cin >> x[i];
#define Test int T; cin >> T;while (T--)
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int MAX_VERTICES = 2e5 + 10;

vector<vector<int>> initializeGraph(int vertices, int edges) {
    // Undirected graph representation container to be initialized
    vector<vector<int>> graph(vertices+10);

    // Take vertices s input
    for (int i = 0; i < edges; ++i) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    return graph;
}

bool isCyclicComponent(int& vertex, vector<vector<int>>& graph, bitset<MAX_VERTICES>& visitedVertices) {
    bool result = true;

    stack<int> dfs;
    dfs.push(vertex);

    while (!dfs.empty()) {
        // Get the current node, mark it as visited and pop it from the dfs stack
        int currentVertex = dfs.top();
        visitedVertices[currentVertex] = true;
        dfs.pop();

        // Validate that each node has 2 edges (the whole component is cyclic)
        result = result && (graph[currentVertex].size() == 2);

        // Visit other children
        for (int child: graph[currentVertex])
            if (!visitedVertices[child])
                dfs.push(child);
    }

    return result;
}

int countCyclicComponents(vector<vector<int>>& graph, int vertices, int edges) {
    int result = 0;
    bitset<MAX_VERTICES> visitedVertex(0);

    // Traverse all nodes to make sure you visit all components
    for (int vertex = 1; vertex <= vertices; ++vertex)
        if (!visitedVertex[vertex])
            result += (isCyclicComponent(vertex, graph, visitedVertex)? 1:0);

    return result;
}

int omar(){ fastIO
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> graph = initializeGraph(vertices, edges);

    int cyclicComponents = countCyclicComponents(graph, vertices, edges);
    cout << cyclicComponents << endl;

}
