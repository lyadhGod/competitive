#include <bits/stdc++.h>
#include "../../Helpers/helpers.h"

using namespace std;

// Time: O(V + E); Space: O(V);
void dfs_traversal(const unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, const int root, const bool _debug = false, const bool _init = true) {
  if (_init) {
    if (_debug) {
      cout << "(";
    }

    dfs_traversal(graph, visited, root, _debug, false);

    if (_debug) {
      cout << ")";
    }

    return;
  }
  
  if (_debug) {
    cout << root;
  }

  visited.emplace(root);

  vector<int> node_vector = graph.find(root)->second;
  vector<int>::const_iterator start = node_vector.begin(), end = node_vector.end(), itr;
  for (itr = start; itr != end; itr++) {
    if (visited.find(*itr) == visited.end()) {
      if (_debug) {
        cout << "(";
      }

      dfs_traversal(graph, visited, *itr, _debug, false);

      if (_debug) {
        cout << ")";
      }
    }
  }
}

int main() {
  unordered_map<int, vector<int>> graph = inp_graph_unweighted();

  unordered_set<int> visited;
  dfs_traversal(graph, visited, 0, true);
  
  return 0;
}


