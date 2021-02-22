#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, vector<int>>& graph, int node, unordered_map<int, bool>& visited) {
    visited[node] = true;
    vector<int> edges = graph[node];
    for (int i = 0; i < edges.size(); i++) {
        if (!visited[edges[i]]) {
            dfs(graph, edges[i], visited);
        }
    }
}

bool detectCycleUndirectedGraph(unordered_map<int, vector<int>>& graph, int node, unordered_map<int, bool>& visited) {
    visited[node] = true;
    vector<int> edges = graph[node];
    for (int i = 0; i < edges.size(); i++) {
        if (!visited[edges[i]]) {
            if (detectCycleUndirectedGraph(graph, i, visited)) {
                return true;
            }
        } else if (edges[i] != node) {
            return true;
        }
    }
    return false;
}

bool detectCycleInDirectedGraph(unordered_map<int, vector<int>>& graph, int node, unordered_map<int, int>& visited) {
    visited[node] = 2;
    vector<int> edges = graph[node];
    for (int i = 0; i < edges.size(); i++) {
        if (visited[edges[i]] == 1 and detectCycleInDirectedGraph(graph, edges[i], visited)) {
            return true;
        }
        if (visited[edges[i]] == 2) {
            return true;
        }
    }
    visited[node] = 3;
    return false;
}

void topologicalSorting(unordered_map<int, vector<int>>& graph, int node, stack<int>& stk, unordered_map<int, int>& visited) {
    visited[node] = true;
    vector<int> edges = graph[node];
    for (int i = 0; i < edges.size(); i++) {
        if (!visited[edges[i]])
            topologicalSorting(graph, node, stk, visited);
    }
    stk.push(node);
}