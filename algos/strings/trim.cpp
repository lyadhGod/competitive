#include <bits/stdc++.h>
#include "../../helpers/helpers.h"

using namespace std;

// Time: O(N); Space: O(N);
string l_trim(
  const string& s,
  const string& d = " ",
  const bool& _debug = true
) {
  size_t start = s.find_first_not_of(d);

  if (start == string::npos) {
    return "";
  }

  size_t last = s.size();
  string ans = s.substr(start, last - start);

  if (_debug) {
    out_string(ans, "l_trim()");
    cout << "\n";
  }

  return ans;
}

// Time: O(N); Space: O(N);
string r_trim(
  const string& s,
  const string& d = " ",
  const bool& _debug = true
) {
  size_t last = s.find_last_not_of(d);

  if (last == string::npos) {
    return "";
  }

  size_t start = 0;
  string ans = s.substr(start, last - start + 1);

  if (_debug) {
    out_string(ans, "r_trim()");
    cout << "\n";
  }

  return ans;
}

// Time: O(N); Space: O(N);
string trim(
  const string& s,
  const string& d = " ",
  const bool& _debug = true
) {
  size_t start = s.find_first_not_of(d);

  if (start == string::npos) {
    return "";
  }

  size_t last = s.find_last_not_of(d);
  string ans = s.substr(start, last - start + 1);

  if (_debug) {
    out_string(ans, "trim()");
    cout << "\n";
  }

  return ans;
}

int main() {
  string s = inp_string(s);

  l_trim(s, " ");
  r_trim(s, " ");
  trim(s, " ");

  return 0;
}
