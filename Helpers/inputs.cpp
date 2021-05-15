#include<bits/stdc++.h>

using namespace std;

string inp_string(bool with_space = true, bool wants_dummy = true) {
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
string inp_string_to_container(string& s, bool with_space = true, bool wants_dummy = true) {
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

unordered_map<int, vector<int>> inp_graph(bool wants_dummy = true) {
  unordered_map<int, vector<int>> graph;

  if (!wants_dummy) {
    cout << "Nodes count (min. 1): ";
    int N;
    cin >> N;

    if (N < 1) {
      exit(0);
    }

    cout << "\nNodes: [ 0";
    for(int i = 1; i < N; i++) {
      cout << ", " << i;
    }
    cout << " ]\n\n";

    cout << "Graph (add \'->\' separated linked nodes):\n";
    string s;
    for(int i = 0; i < N; i++) {
      cout << "[" << i << "]: ";
      getline(cin, s);

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
