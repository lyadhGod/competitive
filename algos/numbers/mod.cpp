#include <bits/stdc++.h>
#include "../../helpers/helpers.h"

using namespace std;

// Time: O(1); Space: O(1);
int mod_add(
  const int& a,
  const int& b,
  const int& mod = 1000000007
) {
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

  int res = x + y;
  if (res < 0) {
    res += mod;
  } else if (res >= mod) {
    res %= mod;
  }

  return res;
}

// Time: O(1); Space: O(1);
int mod_sub(
  const int& a,
  const int& b,
  const int& mod = 1000000007
) {
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

  int res = x - y;
  if (res < 0) {
    res += mod;
  } else if (res >= mod) {
    res %= mod;
  }

  return res;
}

// Time: O(1); Space: O(1);
int mod_mul(
  const int& a,
  const int& b,
  const int& mod = 1000000007
) {
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
}

int main() {
  int res;

  int a = inp_int("a", true, -10, 10);
  int b = inp_int("b", true, -10, 10);
  unsigned int mod = 1000000007;

  res = mod_add(a, b, mod);
  out_int(res, "mod_add()");

  res = mod_sub(a, b, mod);
  out_int(res, "mod_sub()");

  res = mod_mul(a, b, mod);
  out_int(res, "mod_mul()");

  return 0;
}
