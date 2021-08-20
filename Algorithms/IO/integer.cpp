#include<bits/stdc++.h>
#include "../../Helpers/helpers.h"

using namespace std;

// Time: O(M); Space: O(1);
void fast_inp_int(
  int& num,
  const char& delim = ' ',
  const bool& _debug = true
) {
  if (_debug) {
    cout << "input for fast_inp_int(): ";
  }

  bool negative = false;
  register int c;

  c = getchar();
  while (c == delim) {
      c = getchar();
  };
  if (c == '-') {
      negative = true;
      c = getchar();
  }

  num = 0;
  for (; (c > 47 && c < 58); c = getchar()) {
      num = (num << 3) + (num << 1) + (c - 48);
  }

  if (negative) {
      num *= -1;
  }

  if (_debug) {
    out_int(num, "fast_inp_int()");
    cout << "\n";
  }
}

// Time: O(M); Space: O(1);
void fast_inp_long_long(
  long long& num,
  const char& delim = ' ',
  const bool& _debug = true
) {
  if (_debug) {
    cout << "input for fast_inp_long_long(): ";
  }

  bool negative = false;
  register int c;

  c = getchar();
  while (c == delim) {
      c = getchar();
  };
  if (c == '-') {
      negative = true;
      c = getchar();
  }

  num = 0LL;
  for (; (c > 47 && c < 58); c = getchar()) {
      num = (num << 3) + (num << 1) + (c - 48);
  }

  if (negative) {
      num *= -1;
  }

  if (_debug) {
    out_long_long(num, "fast_inp_long_long()");
    cout << "\n";
  }
}

// Time: O(NM); Space: O(1);
void fast_inp_vector_int(
  vector<int>& vect,
  const char& delim = ' ',
  const bool& _debug = true
) {
  if (_debug) {
    cout << "input for " << vect.size() << " values for fast_inp_vector_int(): ";
  }

  int n = vect.size();

  int i;
  for (i = 0; i < n; i++) {
    fast_inp_int(vect[i], delim, false);
  }

  if (_debug) {
    out_vector_int(vect, "fast_inp_vector_int()");
    cout << "\n";
  }
}

// Time: O(NM); Space: O(1);
void fast_inp_vector_long_long(
  vector<long long>& vect,
  const char& delim = ' ',
  const bool& _debug = true
) {
  if (_debug) {
    cout << "input for " << vect.size() << " values for fast_inp_vector_long_long(): ";
  }

  int n = vect.size();

  int i;
  for (i = 0; i < n; i++) {
    fast_inp_long_long(vect[i], delim, false);
  }

  if (_debug) {
    out_vector_long_long(vect, "fast_inp_vector_long_long()");
    cout << "\n";
  }
}

int main() {
  int a;
  fast_inp_int(a);

  long long b;
  fast_inp_long_long(b);

  vector<int> c(a);
  fast_inp_vector_int(c);

  vector<long long> d(a);
  fast_inp_vector_long_long(d);
  
  return 0;
}
