#pragma once

#include <bits/stdc++.h>

using namespace std;

void out_int(
  const int value,
  const string& label = ""
) {
  if (label.size() > 0) {
    cout << label << ": ";
  }
  cout << value << "\n";
}

void out_long_long(
  const long long value,
  const string& label = ""
) {
  if (label.size() > 0) {
    cout << label << ": ";
  }
  cout << value << "\n";
}

void out_double(
  const double value,
  const string& label = ""
) {
  if (label.size() > 0) {
    cout << label << ": ";
  }
  cout << value << "\n";
}

void out_string(
  const string& value,
  const string& label = ""
) {
  if (label.size() > 0) {
    cout << label << ": ";
  }
  cout << "\"" << value << "\"\n";
}

void out_vector_int(
  const vector<int>& value,
  const string& label = ""
) {
  if (label.size() > 0) {
    cout << label << ": ";
  }
  cout << "[ ";

  int i, length = value.size();
  for (i = 0; i < length; i++) {
    cout << value[i] << ", ";
  }

  cout << "]\n";
}

void out_vector_long_long(
  const vector<long long>& value,
  const string& label = ""
) {
  if (label.size() > 0) {
    cout << label << ": ";
  }
  cout << "[ ";

  int i, length = value.size();
  for (i = 0; i < length; i++) {
    cout << value[i] << ", ";
  }

  cout << "]\n";
}

void out_vector_double(
  const vector<double>& value,
  const string& label = ""
) {
  if (label.size() > 0) {
    cout << label << ": ";
  }
  cout << "[ ";

  int i, length = value.size();
  for (i = 0; i < length; i++) {
    cout << value[i] << ", ";
  }

  cout << "]\n";
}

void out_vector_string(
  const vector<string>& value,
  const string& label = ""
) {
  if (label.size() > 0) {
    cout << label << ": ";
  }
  cout << "[ ";

  int i, length = value.size();
  for (i = 0; i < length; i++) {
    cout << "\"" << value[i] << "\", ";
  }

  cout << "]\n";
}

void out_matrix_int(
  const vector<vector<int>>& value,
  const string& label = ""
) {
  if (label.size() > 0) {
    cout << label << ": ";
  }
  cout << "[\n";

  int length_i = value.size(), length_j;
  if (length_i > 0) {
    length_j = value[0].size();
  }

  int i, j;
  for (i = 0; i < length_i; i++) {
    cout << "    [ ";
  
    for (j = 0; j < length_j; j++) {
      cout << value[i][j] << ", ";
    }

    cout << "],\n";
  }

  cout << "]\n";
}

void out_matrix_long_long(
  const vector<vector<long long>>& value,
  const string& label = ""
) {
  if (label.size() > 0) {
    cout << label << ": ";
  }
  cout << "[\n";

  int length_i = value.size(), length_j;
  if (length_i > 0) {
    length_j = value[0].size();
  }

  int i, j;
  for (i = 0; i < length_i; i++) {
    cout << "    [ ";
  
    for (j = 0; j < length_j; j++) {
      cout << value[i][j] << ", ";
    }

    cout << "],\n";
  }

  cout << "]\n";
}

void out_matrix_double(
  const vector<vector<double>>& value,
  const string& label = ""
) {
  if (label.size() > 0) {
    cout << label << ": ";
  }
  cout << "[\n";

  int length_i = value.size(), length_j;
  if (length_i > 0) {
    length_j = value[0].size();
  }

  int i, j;
  for (i = 0; i < length_i; i++) {
    cout << "    [ ";
  
    for (j = 0; j < length_j; j++) {
      cout << value[i][j] << ", ";
    }

    cout << "],\n";
  }

  cout << "]\n";
}

void out_unweighted_graph(
  const unordered_map<int, vector<int>>& value,
  const string& label = ""
) {
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

void out_weighted_graph(
  const unordered_map<int, vector<pair<int, int>>>& value,
  const string& label = ""
) {
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

void out_transtion_char_char(
  const vector<pair<char, char>>& value,
  const string& label = ""
) {
  if (label.size() > 0) {
    cout << label << ": ";
  }
  cout << "[\n";

  int i, length = value.size();
  for (i = 0; i < length; i++) {
    cout << "    \'" << value[i].first << "\' -> \'" << value[i].second << "\'\n";
  }

  cout << "]\n";
}

void out_transtion_char_char_all(
  const vector<vector<pair<char, char>>>& value,
  const string& label = ""
) {
  if (label.size() > 0) {
    cout << label << ": ";
  }
  cout << "[\n";

  int i, j, length_i = value.size(), length_j;;
  for (i = 0; i < length_i; i++) {
    cout << "    [ ";

    length_j = value[i].size();
    for (j = 0; j < length_j; j++) {
      cout << "\'" << value[i][j].first << "\' -> \'" << value[i][j].second << "\', ";
    }

    cout << "]\n";
  }

  cout << "]\n";
}


