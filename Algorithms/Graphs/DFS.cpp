#include <bits/stdc++.h>
#include "../../Helpers/helpers.h"

using namespace std;

// Time: O(V + E); Space: O(V);
void dfs_traversal(
  const unordered_map<int, vector<int>>& graph,
  const int& root,
  const bool& _debug = true
) {
  auto dfs = [](
    const unordered_map<int, vector<int>>& graph,
    unordered_set<int>& visited,
    const int& root,
    const bool& _debug,
    const auto& _self
  ) -> void {
    if (_debug) {
      cout << root;
    }

    visited.emplace(root);

    auto node_vector = graph.find(root)->second;
    auto start = node_vector.begin(), end = node_vector.end();
    auto itr = start;
    for (itr = start; itr != end; itr++) {
      if (visited.find(*itr) == visited.end()) {
        if (_debug) {
          cout << "(";
        }

        _self(graph, visited, *itr, _debug, _self);

        if (_debug) {
          cout << ")";
        }
      }
    }
  };

  unordered_set<int> visited;

  if (_debug) {
    cout << "output: (";
  }

  dfs(graph, visited, root, _debug, dfs);

  if (_debug) {
    cout << ")\n";
  }
}

int main() {
  unordered_map<int, vector<int>> graph = inp_graph_unweighted("graph");

  dfs_traversal(graph, 0);
  
  return 0;
}


