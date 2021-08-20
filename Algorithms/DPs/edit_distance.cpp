#include <bits/stdc++.h>
#include "../../Helpers/helpers.h"

using namespace std;

// Time: O(N^2); Space: O(N^2);
int edit_distance_num(
  const string& from,
  const string& to,
  const int addition_cost = 1,
  const int editting_cost = 1,
  const int deletion_cost = 1,
  const bool _debug = true
) {
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
    cout << "\n";
  }

  return ans;
}

// Time: O(N^2); Space: O(N^2);
vector<pair<char, char>> edit_distance_string(
  const string& from,
  const string& to,
  const int addition_cost = 1,
  const int editting_cost = 1,
  const int deletion_cost = 1,
  const bool _debug = true
) {
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
    k++;
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
    cout << "\n";
  }

  return ans;
}

// Time: O(N^2); Space: O(N^2);
vector<vector<pair<char, char>>> edit_distance_string_all(
  const string& from,
  const string& to,
  const int addition_cost = 1,
  const int editting_cost = 1,
  const int deletion_cost = 1,
  const bool _debug = true
) {
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

  vector<vector<pair<char, char>>> ans;

  ans.emplace_back(vector<pair<char, char>>());
  auto func = ([&from, &to, addition_cost, editting_cost, deletion_cost, &vect, &ans](int i, int j, int k, auto& _self) -> void {
    int count;
    while (i > 0 && j > 0) {
      if (from[j - 1] == to[i - 1]) {
        ans[k].emplace_back(make_pair(from[j - 1], to[i - 1]));
        i--;
        j--;
      } else {
        count = 0;
        if (vect[i][j] == (vect[i - 1][j] + addition_cost)) {
          count++;
        }
        if (vect[i][j] == (vect[i - 1][j - 1] + editting_cost)) {
          count++;
        }
        if (vect[i][j] == (vect[i][j - 1] + deletion_cost)) {
          count++;
        }

        if (count == 1) {
          if (vect[i][j] == (vect[i - 1][j] + addition_cost)) {
            ans[k].emplace_back(make_pair(' ', to[i - 1]));
            i--;
          } else if (vect[i][j] == (vect[i - 1][j - 1] + editting_cost)) {
            ans[k].emplace_back(make_pair(from[j - 1], to[i - 1]));
            i--;
            j--;
          } else {
            ans[k].emplace_back(make_pair(from[j - 1], ' '));
            j--;
          }
        } else { 
          if (vect[i][j] == (vect[i - 1][j] + addition_cost)) {
            ans.emplace_back(vector<pair<char, char>>(ans[k].begin(), ans[k].end()));
            ans[ans.size() - 1].emplace_back(make_pair(' ', to[i - 1]));
            _self(i - 1, j, ans.size() - 1, _self);
          } 
          if (vect[i][j] == (vect[i - 1][j - 1] + editting_cost)) {
            ans.emplace_back(vector<pair<char, char>>(ans[k].begin(), ans[k].end()));
            ans[ans.size() - 1].emplace_back(make_pair(from[j - 1], to[i - 1]));
            _self(i - 1, j - 1, ans.size() - 1, _self);
          }
          if (vect[i][j] == (vect[i][j - 1] + deletion_cost)) {
            ans.emplace_back(vector<pair<char, char>>(ans[k].begin(), ans[k].end()));
            ans[ans.size() - 1].emplace_back(make_pair(from[j - 1], ' '));
            _self(i, j - 1, ans.size() - 1, _self);
          }
          ans.erase(ans.begin() + k);
          return;
        }
      }
    } 
    while (i > 0) {
      ans[k].emplace_back(make_pair(' ', to[i - 1]));
      i--;
    }
    while (j > 0) {
      ans[k].emplace_back(make_pair(from[j - 1], ' '));
      j--;
    }
    ans[k].shrink_to_fit();
  });

  func(rows_count - 1, columns_count - 1, 0, func);
  ans.shrink_to_fit();

  if (_debug) {
    out_matrix_int(vect, "edit_distance_string_all()[ vect ]");
    out_transtion_char_char_all(ans, "edit_distance_string_all()");
    cout << "\n";
  }

  return ans;
}

int main() {
  string from = inp_string(false, true);
  string to = inp_string(false, true);

  edit_distance_num(from, to, 1, 1, 1);
  edit_distance_string(from, to, 1, 1, 1);
  edit_distance_string_all(from, to, 1, 1, 1);

  return 0;
}


