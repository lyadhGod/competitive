#include <bits/stdc++.h>
#include "../../Helpers/helpers.h"

using namespace std;

// Time: O(1); Space: O(1);
int mod_add(
  const int& a,
  const int& b,
  const unsigned int& mod,
  const bool& _debug = true
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

  if (_debug) {
    out_int(x, "mod_add()[ x ]");
    out_int(y, "mod_add()[ y ]");
    out_int(res, "mod_add()");
    cout << "\n";
  }

  return res;
}

// Time: O(1); Space: O(1);
int mod_sub(
  const int& a,
  const int& b,
  const unsigned int& mod,
  const bool& _debug = true
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

  if (_debug) {
    out_int(x, "mod_add()[ x ]");
    out_int(y, "mod_add()[ y ]");
    out_int(res, "mod_sub()");
    cout << "\n";
  }

  return res;
}

// Time: O(1); Space: O(1);
int mod_mul(
  const int& a,
  const int& b,
  const unsigned int& mod,
  const bool& _debug = true
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

  if (_debug) {
    out_int(x, "mod_add()[ x ]");
    out_int(y, "mod_add()[ y ]");
    out_int(res, "mod_mul()");
    cout << "\n";
  }

  return res;
}

int main() {
  int a = inp_int("a", true, -10, 10);
  int b = inp_int("b", true, -10, 10);
  unsigned int mod = 1000000007;

  mod_add(a, b, mod);
  mod_sub(a, b, mod);
  mod_mul(a, b, mod);

  return 0;
}
