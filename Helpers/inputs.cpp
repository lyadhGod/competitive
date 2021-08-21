#pragma once

#include <bits/stdc++.h>
#include "random.cpp"
#include "outputs.cpp"

using namespace std;

// input an integer in range [`min`, `max`]
int inp_int(const string& label, const int& min = -1000000007, const int& max = 1000000007, const bool& _dummy = true) {
  int s;

  cout << label << ": ";
  if (!_dummy) {
    cin >> s;
  } else {
    s = gen_random_int(min, max);
    out_int(s);
  }

  return s;
}

// input a string with/without spaces
string inp_string(const string& label, const bool& with_space = false, const bool& _dummy = true) {
  string s;

  cout << label << ": ";
  if (!_dummy) {
    if (with_space) {
      getline(cin, s);
    } else {
      cin >> s;
    }
  } else {
    s = gen_random_string(10U, with_space);
    out_string(s);
  }

  return s;
}

// input an integer vector of length `length` containing values in range [`min`, `max`]
vector<int> inp_vector_int(const string& label, const int& length = 10, const int& min = -1000000007, const int& max = 1000000007, const bool& _dummy = true) {
  vector<int> s;

  cout << label << ": ";
  if (!_dummy) {
    cout << "\n";
    
    cout << "element count: ";
    int n;
    cin >> n;

    int i, j;
    s.resize(n);

    cout << "vector (\' \' separated elements):\n";
    for (i = 0; i < n; i++) {
      cin >> s[i];
    }
  } else {
    s = gen_random_vector_int(length, min, max);
    out_vector_int(s);
  }

  return s;
}

unordered_map<int, vector<int>> inp_graph_unweighted(const string& label, const unsigned int& length = 10U, const bool& _dummy = true) {
  unordered_map<int, vector<int>> graph;

  cout << label << ":\n";
  if (!_dummy) {
    cout << "nodes count: ";
    int N;
    cin >> N;

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
      cout << "    (" << i << ") -> ";
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
  } else {
    graph = gen_random_unweighted_graph(length);
    out_unweighted_graph(graph, "input graph");
  }

  return graph;
}

// input an integer vector of row count `rows` and column count `columns` containing values in range [`min`, `max`]
vector<vector<int>> inp_matrix_int(const string& label, const int& rows = 2, const int& columns = 3, const int& min = -1000000007, const int& max = 1000000007, const bool& _dummy = true) {
  vector<vector<int>> s;

  cout << label << ": ";
  if (!_dummy) {
    cout << "\n";
    
    cout << "rows count: ";
    int n;
    cin >> n;

    cout << "columns count: ";
    int m;
    cin >> m;

    int i, j;
    s.resize(n);
    for (i = 0; i < n; i++) {
      s[i].resize(m);
    }

    cout << "matrix (\' \' separated column values):\n";
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        cin >> s[i][j];
      }
    }
  } else {
    s = gen_random_matrix(rows, columns, min, max);
    out_matrix_int(s);
  }

  return s;
}

// input a tree as vector where each index is a node and it's value is it's parent
// root node has itself as it's parent
vector<int> inp_tree(const string& label, const int& nodes = 10, const bool& _dummy = true) {
  vector<int> inp;

  cout << label << ": ";
  if (!_dummy) {
    cout << "\n";
    
    cout << "node count: ";
    int n;
    cin >> n;

    inp.resize(n);

    cout << "parent valued tree: [\n";
    int i;
    for (i = 0; i < n; i++) {
      cout << "    " << i << ": ";
      cin >> inp[i];
    }
    cout << "]\n";
  } else {
    inp = gen_random_tree(nodes);
    out_vector_int(inp, "", true);
  }

  return inp;
}