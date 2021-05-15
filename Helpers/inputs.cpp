#include<bits/stdc++.h>

using namespace std;


string inp_string(const bool with_space = true, const bool wants_dummy = true) {
  string s;

  cout << "Input String: ";
  if (!wants_dummy) {
    if (with_space) {
      getline(cin, s);
    } else {
      cin >> s;
    }
  } else {
    if (with_space) {
      s = "Black Lives Matter";
    } else {
      s = "Black";
    }
    cout << s << "\n";
  }

  return s;
}

unordered_map<int, vector<int>> inp_graph_unweighted(const bool wants_dummy = true) {
  unordered_map<int, vector<int>> graph;

  if (!wants_dummy) {
    cout << "Nodes count: ";
    int N;
    cin >> N;

    if (N < 1) {
      return graph;
    }

    cout << "\nNodes: [ 0";
    for(int i = 1; i < N; i++) {
      cout << ", " << i;
    }
    cout << " ]\n\n";

    cout << "Graph (\'->\' separated linked nodes):\n";
    string s;
    int j, count;
    size_t start, end;
    vector<string> v;
    for (int i = 0; i < N; i++) {
      cout << "[" << i << "]: ";
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

        cout << "\"" << v[j] << "\"   ";
      }
      cout << "\n";
    }
  }

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

  return graph;
}
