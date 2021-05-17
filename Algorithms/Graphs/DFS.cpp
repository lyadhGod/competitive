#include<bits/stdc++.h>

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

unordered_map<int, vector<int>> inp_graph_unweighted(const bool _dummy = true) {
  unordered_map<int, vector<int>> graph;

  if (!_dummy) {
    cout << "nodes count: ";
    int N;
    cin >> N;

    if (N > 0) {
      int i;

      cout << "\nnodes: [ 0";
      for(i = 1; i < N; i++) {
        cout << ", " << i;
      }
      cout << " ]\n\n";

      cout << "graph (\'->\' separated linked nodes):\n";
      string s;
      int j, count;
      size_t start, end;
      vector<string> v;
      for (i = 0; i < N; i++) {
        cout << "[" << i << "] -> ";
        getline(cin, s);

        count = 0;
        start = 0;
        end = s.find_first_of("->");
        while (end != string::npos) {
          count++;
          start = end + 1;
          end = s.find_first_of("->", start);
        }
        v.resize(count + 1);

        j = 0;
        start = 0;
        end = s.find_first_of("->");
        while (end != string::npos) {
          v[j++] = s.substr(start, end - start);
          start = end + 1;
          end = s.find_first_of("->", start);
        }
        v[j++] = s.substr(start, end - start);

        for (j = 0; j < count; j++) {
          start = v[j].find_first_not_of(" ");
          if (start != string::npos) {
            end = v[j].find_last_not_of(" ");
            v[j] = v[j].substr(start, end - start + 1);
          }
        }

        graph[i].resize(count + 1);
      }
    }
  } else {
    graph[0] = vector<int>{ 1, 4 };
    graph[1] = vector<int>{ 0, 2 };
    graph[2] = vector<int>{ 1, 4 };
    graph[3] = vector<int>{ 0, 2, 5 };
    graph[4] = vector<int>{ 5 };
    graph[5] = vector<int>{ 8 };
    graph[6] = vector<int>{ 7, 9 };
    graph[7] = vector<int>{ 6, 9 };
    graph[8] = vector<int>{ 3, 4 };
    graph[9] = vector<int>{ 6, 7 };

    cout << "nodes count: 10\n";
    cout << "nodes: [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ]\n";
    cout << "graph (\'->\' separated linked nodes): {\n";
    cout << "[0] -> 1 -> 4\n";
    cout << "[1] -> 0 -> 2\n";
    cout << "[2] -> 1 -> 4\n";
    cout << "[3] -> 0 -> 2 -> 5\n";
    cout << "[4] -> 5\n";
    cout << "[5] -> 8\n";
    cout << "[6] -> 7 -> 9\n";
    cout << "[7] -> 6 -> 9\n";
    cout << "[8] -> 3 -> 4\n";
    cout << "[9] -> 6 -> 7\n";
    cout << "}\n";
  }

  return graph;
}

int main() {
  unordered_map<int, vector<int>> graph = inp_graph_unweighted();

  unordered_set<int> visited;
  dfs_traversal(graph, visited, 0, true);
  
  return 0;
}