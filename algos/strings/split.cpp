#include <bits/stdc++.h>
#include "../../helpers/helpers.h"

using namespace std;

// Time: O(N); Space: O(N); 
vector<string> split(
  const string& s,
  const string& d = " ",
  const bool& _debug = true
) {
  vector<string> v;

  int i;
  if (d.size() == 0) {
    int len = s.size();

    v.resize(len);

    for (i = 0; i < len; i++) {
      v[i] = s[i];
    }
  } else {
    size_t start, end;

    int count = 0;
    start = 0;
    end = s.find_first_of(d);
    while (end != string::npos) {
      count++;
      start = end + 1;
      end = s.find_first_of(d, start);
    }

    v.resize(count + 1);

    i = 0;
    start = 0;
    end = s.find_first_of(d);
    while (end != string::npos) {
      v[i++] = s.substr(start, end - start);
      start = end + 1;
      end = s.find_first_of(d, start);
    }
    v[i++] = s.substr(start, end - start);
  }

  if (_debug) {
    out_vector_string(v, "split()");
    cout << "\n";
  }

  return v;
}

int main() {
  string s = inp_string("s");

  split(s, " ");

  return 0;
}
