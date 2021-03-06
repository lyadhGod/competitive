#include <bits/stdc++.h>
#include "../../helpers/helpers.h"

using namespace std;

// Time: O(logN); Space: O(1);
int pow_integer(
  const int& num,
  const unsigned int& exp
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

  return res;
}

// Time: O(logN); Space: O(1);
int pow_integer_mod(
  const int& num,
  const unsigned int& exp,
  const unsigned int& mod
) {
  unsigned int a = exp;
  int n = num;
  if (n < 0) {
    n *= -1;
  }

  // FROM /algos/numbers/mod.cpp#mod_mul()
  auto mod_mul = [&](
    const int& a,
    const int& b,
    const unsigned int& mod
  ) -> int {
    int x = a;
    if (x < 0) {
      x += mod;
    } else if (x >= mod) {
      x %= mod;
    }

    int y = b;
    if (y < 0) {
      y += mod;
    } else if (y >= mod) {
      y %= mod;
    }

    int res = x * y;
    if (res < 0) {
      res += mod;
    } else if (res >= mod) {
      res %= mod;
    }

    return res;
  };

  int res = 1;
  while (a > 0) {
    if (a & 1) {
      res = mod_mul(res, n, mod);
    }
    n = mod_mul(n, n, mod);
    a >>= 1;
  }

  if ((num < 0) && (exp & 1)) {
    res *= -1;
  }

  return res;
}

int main() {
  int res;

  int num = inp_int("num", true, -10, 10);
  unsigned int exp_int = inp_int("exp", true, 0, 10);

  res = pow_integer(num, exp_int);
  out_int(res, "pow_integer()");

  res = pow_integer_mod(num, exp_int, 1000000007);
  out_int(res, "pow_integer_mod()");

  return 0;
}
