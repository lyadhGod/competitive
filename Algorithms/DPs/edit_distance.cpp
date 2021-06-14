#include <bits/stdc++.h>
#include "../../Helpers/helpers.h"

using namespace std;

// Time: O(N^2); Space: O(N^2);
int edit_distance_num(const string& from, const string& to, const int addition_cost = 1, const int editting_cost = 1, const int deletion_cost = 1, const bool _debug = false) {
  int i, j;
  
  int rows_count = to.size() + 1, columns_count = from.size() + 1;
  vector<vector<int>> vect(rows_count);
  for (i = 0; i < rows_count; i++) {
    vect[i].resize(columns_count);
  }

  vect[0][0] = 0;
  for (i = 1; i < rows_count; i++) {
    vect[i][0] = vect[i - 1][0] + addition_cost;
  }
  for (j = 1; j < columns_count; j++) {
    vect[0][j] = vect[0][j - 1] + deletion_cost;
  }

  for (i = 1; i < rows_count; i++) {
    for (j = 1; j < columns_count; j++) {
      if (from[j - 1] == to[i - 1]) {
        vect[i][j] = vect[i - 1][j - 1];
      } else {
        vect[i][j] = min(
          vect[i - 1][j] + addition_cost,
          min(
            vect[i - 1][j - 1] + editting_cost,
            vect[i][j - 1] + deletion_cost
          )
        );
      }
    }
  }

  int ans = vect[rows_count - 1][columns_count - 1];

  if (_debug) {
    out_matrix_int(vect, "edit_distance_num()[ vect ]");
    out_int(ans, "edit_distance_num()");
  }

  return ans;
}

// Time: O(N^2); Space: O(N^2);
vector<pair<char, char>> edit_distance_string(const string& from, const string& to, const int addition_cost = 1, const int editting_cost = 1, const int deletion_cost = 1, const bool _debug = false) {
  int i, j, k;
  
  int rows_count = to.size() + 1, columns_count = from.size() + 1;
  vector<vector<int>> vect(rows_count);
  for (i = 0; i < rows_count; i++) {
    vect[i].resize(columns_count);
  }

  vect[0][0] = 0;
  for (i = 1; i < rows_count; i++) {
    vect[i][0] = vect[i - 1][0] + addition_cost;
  }
  for (j = 1; j < columns_count; j++) {
    vect[0][j] = vect[0][j - 1] + deletion_cost;
  }

  for (i = 1; i < rows_count; i++) {
    for (j = 1; j < columns_count; j++) {
      if (from[j - 1] == to[i - 1]) {
        vect[i][j] = vect[i - 1][j - 1];
      } else {
        vect[i][j] = min(
          vect[i - 1][j] + addition_cost,
          min(
            vect[i - 1][j - 1] + editting_cost,
            vect[i][j - 1] + deletion_cost
          )
        );
      }
    }
  }

  vector<pair<char, char>> ans(rows_count + columns_count);
  
  k = 0;
  i = rows_count - 1;
  j = columns_count - 1;
  while (i > 0 && j > 0) {
    if (from[j - 1] == to[i - 1]) {
      ans[k] = make_pair(from[j - 1], to[i - 1]);
      i--;
      j--;
    } else {
      if (vect[i][j] == (vect[i - 1][j] + addition_cost)) {
        ans[k] = make_pair(' ', to[i - 1]);
        i--;
      } else if (vect[i][j] == (vect[i - 1][j - 1] + editting_cost)) {
        ans[k] = make_pair(from[j - 1], to[i - 1]);
        i--;
        j--;
      } else {
        ans[k] = make_pair(from[j - 1], ' ');
        j--;
      }
    }
    k++; out_transtion_char_char(ans);
  }
  while (i > 0) {
    ans[k] = make_pair(' ', to[i - 1]);
    i--;
    k++;
  }
  while (j > 0) {
    ans[k] = make_pair(from[j - 1], ' ');
    j--;
    k++;
  }

  ans.resize(k);

  if (_debug) {
    out_matrix_int(vect, "edit_distance_string()[ vect ]");
    out_transtion_char_char(ans, "edit_distance_string()");
  }

  return ans;
}

int main() {
  string from = inp_string(false, false);
  string to = inp_string(false, false);

  edit_distance_string(from, to, 1, 1, 1, true);

  return 0;
}


