#include <bits/stdc++.h>
#include "../../Helpers/helpers.h"

using namespace std;

// Time: O(logN); Space: O(1);
int pow_int(
  const int& num,
  const unsigned int& exp,
  const bool& _debug = true
) {
  unsigned int a = exp;
  int n = num;
  if (n < 0) {
    n *= -1;
  }

  int res = 1;
  while (a > 0) {
    if (a & 1) {
      res *= n;
    }
    n *= n;
    a >>= 1;
  }

  if ((num < 0) && (exp & 1)) {
    res *= -1;
  }

  if (_debug) {
    out_int(res, "pow_int()");
    cout << "\n";
  }

  return res;
}

// Time: O(logN); Space: O(1);
int pow_long_long(
  const long long& num,
  const unsigned long long& exp,
  const bool& _debug = true
) {
  unsigned long long a = exp;
  long long n = num;
  if (n < 0LL) {
    n *= -1LL;
  }

  long long res = 1LL;
  while (a > 0LL) {
    if (a & 1LL) {
      res *= n;
    }
    n *= n;
    a >>= 1;
  }

  if ((num < 0LL) && (exp & 1LL)) {
    res *= -1LL;
  }

  if (_debug) {
    out_long_long(res, "pow_long_long()");
    cout << "\n";
  }

  return res;
}

int main() {
  int num_int = inp_int("num_int", -10, 10);
  unsigned int exp_int = inp_int("exp_int", 0, 10);
  pow_int(num_int, exp_int);

  long long num_long_long = inp_long_long("num_long_long", -10LL, 10LL);
  unsigned long long exp_long_long = inp_long_long("exp_long_long", 0LL, 10LL);
  pow_long_long(num_long_long, exp_long_long);

  return 0;
}
