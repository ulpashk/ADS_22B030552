#include <iostream>
#include <vector>

using namespace std;

void dfs(int vertex, vector<bool>& visited, const vector<vector<int>>& adjacencyList) {
    visited[vertex] = true;
    for (int neighbor : adjacencyList[vertex]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adjacencyList);
        }
    }
}

bool areInSameComponent(int s, int f, const vector<vector<int>>& adjacencyList) {
    int n = adjacencyList.size();
    vector<bool> visited(n, false);

    dfs(s - 1, visited, adjacencyList);

    return visited[f - 1];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacencyList(n);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adjacencyList[x - 1].push_back(y - 1);
        adjacencyList[y - 1].push_back(x - 1);
    }

    int s, f;
    cin >> s >> f;

    string result = areInSameComponent(s, f, adjacencyList) ? "YES" : "NO";
    cout << result << endl;

    return 0;
}
