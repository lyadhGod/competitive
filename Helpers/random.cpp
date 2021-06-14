#pragma once

#include <bits/stdc++.h>
#include "outputs.cpp"

using namespace std;

int gen_random_int(const int min = -1000000007, const int max = 1000000007, const bool _debug = false) {
  default_random_engine engine(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> distribution(min, max);
  int ans = distribution(engine);

  if (_debug) {
    out_int(ans, "gen_random_int()");
  }

  return ans;
}

long gen_random_long(const long min = -1000000007L, const long max = 1000000007L, const bool _debug = false) {
  default_random_engine engine(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<long> distribution(min, max);
  long ans = distribution(engine);

  if (_debug) {
    out_long(ans, "gen_random_long()");
  }

  return ans;
}

long long gen_random_long_long(const long long min = -1000000007LL, const long long max = 1000000007LL, const bool _debug = false) {
  default_random_engine engine(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<long long> distribution(min, max);
  long long ans = distribution(engine);

  if (_debug) {
    out_long_long(ans, "gen_random_long_long()");
  }

  return ans;
}

double gen_random_double(const double min = -1000000007.0, const double max = 1000000007.0, const bool _debug = false) {
  default_random_engine engine(chrono::system_clock::now().time_since_epoch().count());
  uniform_real_distribution<double> distribution(min, max);
  double ans = distribution(engine);

  if (_debug) {
    out_double(ans, "gen_random_double()");
  }

  return ans;
}

string gen_random_string(const int length = 10, const bool with_space = false, const bool _debug = false) {
  vector<char> char_space = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
  };

  int len = length;
  if (with_space) {
    len = (int) (len / 2);
  }

  default_random_engine engine(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> distribution(0, char_space.size());

  int i;
  string s(length, ' ');
  for (i = 0; i < len; i++) {
    s[i] = char_space[distribution(engine)];
  }
  if (with_space) {
    for (++i; i < length; i++) {
      s[i] = char_space[distribution(engine)];
    }
  }

  if (_debug) {
    out_string(s, "gen_random_string()");
  }

  return s;
}

unordered_map<int, vector<int>> gen_random_unweighted_graph(const int length = 10, const bool has_forced_disconnection = false, const bool _debug = false) {
  default_random_engine engine(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> node_distribution(0, length - 1);
  uniform_int_distribution<int> connected_distribution(0, 1);

  unordered_map<int, vector<int>> graph;

  int i, j;
  int count;
  for (i = 0; i < length; i++) {
    count = node_distribution(engine);

    graph[i] = vector<int>(count);

    if (!(has_forced_disconnection && connected_distribution(engine))) {
      for (j = 0; j < count; j++) {
        graph[i][j] = node_distribution(engine);
      }
    }
  }

  if (_debug) {
    out_unweighted_graph(graph, "gen_random_unweigthed_graph()");
  }

  return graph;
}

unordered_map<int, vector<pair<int, int>>> gen_random_weighted_graph(const int length = 10, const int min_weight = 0, const int max_weight = 10, const bool has_forced_disconnection = false, const bool _debug = false) {
  default_random_engine engine(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> node_distribution(0, length - 1);
  uniform_int_distribution<int> edge_distribution(min_weight, max_weight);
  uniform_int_distribution<int> connected_distribution(0, 1);

  unordered_map<int, vector<pair<int, int>>> graph;

  int i, j;
  int count;
  for (i = 0; i < length; i++) {
    count = node_distribution(engine);

    graph[i] = vector<pair<int, int>>(count);

    if (!(has_forced_disconnection && connected_distribution(engine))) {
      for (j = 0; j < count; j++) {
        graph[i][j] = make_pair(node_distribution(engine), edge_distribution(engine));
      }
    }
  }

  if (_debug) {
    out_weighted_graph(graph, "gen_random_weigthed_graph()");
  }

  return graph;
}


