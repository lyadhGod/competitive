#pragma once

#include <bits/stdc++.h>
#include "random.cpp"
#include "outputs.cpp"

using namespace std;

int inp_int(
  const string& label,
  const int& min = -1000000007,
  const int& max = 1000000007,
  const bool& _dummy = true
) {
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

int inp_long_long(
  const string& label,
  const long long& min = -1000000007LL,
  const long long& max = 1000000007LL,
  const bool& _dummy = true
) {
  int s;

  cout << label << ": ";
  if (!_dummy) {
    cin >> s;
  } else {
    s = gen_random_long_long(min, max);
    out_long_long(s);
  }

  return s;
}

string inp_string(
  const string& label,
  const bool& with_space = false,
  const bool& _dummy = true
) {
  string s;

  cout << label << ": ";
  if (!_dummy) {
    if (with_space) {
      getline(cin, s);
    } else {
      cin >> s;
    }
  } else {
    s = gen_random_string(10, with_space);
    out_string(s);
  }

  return s;
}

unordered_map<int, vector<int>> inp_graph_unweighted(
  const string& label,
  const int& length = 10,
  const bool& _dummy = true
) {
  unordered_map<int, vector<int>> graph;

  cout << label << ":\n";
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
    }
  } else {
    graph = gen_random_unweighted_graph(length);
    out_unweighted_graph(graph, "input graph");
  }

  return graph;
}


