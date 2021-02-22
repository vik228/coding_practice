#include <bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int, vector<int>>& graph, int node) {
    unordered_map<int, bool> visited;
    queue<int> queue;
    queue.push(node);
    visited[node] = true;
    while(!queue.empty()) {
        int front = queue.front();
        queue.pop();
        vector<int> edges = graph[front];
        for (int i = 0; i < edges.size(); i++) {
            if (!visited[edges[i]]) {
                queue.push(edges[i]);
                visited[edges[i]] = true;
            }
        }
    }
}

bool hasPath(unordered_map<int, vector<int>>& graph, int source, int dest) {
    unordered_map<int, bool> visited;
    queue<int> queue;
    queue.push(source);
    visited[source] = true;
    while (!queue.empty()) {
        int front = queue.front();
        queue.pop();
        vector<int> edges = graph[front];
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i] == dest) {
                return true;
            }
            if (!visited[edges[i]]) {
                queue.push(edges[i]);
                visited[edges[i]] = true;
            }
        }
    }
    return false;
}

bool isBipartite(unordered_map<int, vector<int>>& graph, int source) {
    vector<int> color(graph.size(), -1);
    queue<int> queue;
    queue.push(source);
    color[source] = 1;
    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        vector<int> children = graph[node];
        for (int i = 0; i < children.size(); i++) {
            if (color[children[i]] == -1) {
                color[children[i]] = color[node]^1;
                queue.push(children[i]);
            }
            if (color[node] == color[children[i]]) {
                return false;
            }
        }
    }
    return true;
}