#include <bits/stdc++.h>
#include "../../Helpers/helpers.h"

using namespace std;

// Time: O(N^2); Space: O(N^2);
int edit_distance(const string& from, const string& to, const int addition_cost = 1, const int editting_cost = 1, const int deletion_cost = 1, const bool _debug = false) {
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


}

int main() {
  string from = inp_string();
  string to = inp_string();


  return 0;
}


