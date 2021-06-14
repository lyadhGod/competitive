#pragma once

#include <bits/stdc++.h>

using namespace std;

void out_int(const int value, const string& label = "") {
  if (label.size() > 0) {
    cout << label << ": ";
  }
  cout << value << "\n";
}

void out_long(const long value, const string& label = "") {
  if (label.size() > 0) {
    cout << label << ": ";
  }
  cout << value << "\n";
}

void out_long_long(const long long value, const string& label = "") {
  if (label.size() > 0) {
    cout << label << ": ";
  }
  cout << value << "\n";
}

void out_double(const double value, const string& label = "") {
  if (label.size() > 0) {
    cout << label << ": ";
  }
  cout << value << "\n";
}

void out_string(const string& value, const string& label = "") {
  if (label.size() > 0) {
    cout << label << ": ";
  }
  cout << value << "\n";
}

void out_unweighted_graph(const unordered_map<int, vector<int>>& value, const string& label = "") {
  if (label.size() > 0) {
    cout << label << ": ";
  }
  cout << "{\n";

  int count, j;
  unordered_map<int, vector<int>>::const_iterator begin_i = value.begin(), end_i = value.end();
  unordered_map<int, vector<int>>::const_iterator itr;
  for (itr = begin_i; itr != end_i; itr++) {
    cout << "    (" << itr->first << ")";

    count = itr->second.size();
    for (j = 0; j < count; j++) {
      cout << " -> " << itr->second[j];
    }

    cout << "\n";
  }

  cout << "}\n";
}

void out_weighted_graph(const unordered_map<int, vector<pair<int, int>>>& value, const string& label = "") {
  if (label.size() > 0) {
    cout << label << ": ";
  }
  cout << "{\n";

  int count, j;
  unordered_map<int, vector<pair<int, int>>>::const_iterator begin_i = value.begin(), end_i = value.end();
  unordered_map<int, vector<pair<int, int>>>::const_iterator itr;
  for (itr = begin_i; itr != end_i; itr++) {
    cout << "    (" << itr->first << ")";

    count = itr->second.size();
    for (j = 0; j < count; j++) {
      cout << " -> [" << itr->second[j].first << ", " << itr->second[j].second << "]";
    }

    cout << "\n";
  }

  cout << "}\n";
}


