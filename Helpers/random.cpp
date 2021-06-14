#pragma once

#include <bits/stdc++.h>

using namespace std;

int gen_random_int(const int min = -1000000007, const int max = 1000000007, const bool _debug = false) {
  default_random_engine engine(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> distribution(min, max);
  int ans = distribution(engine);

  if (_debug) {
    cout << "gen_random_int(): " << ans << "\n";
  }

  return ans;
}

long gen_random_long(const long min = -1000000007L, const long max = 1000000007L, const bool _debug = false) {
  default_random_engine engine(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<long> distribution(min, max);
  long ans = distribution(engine);

  if (_debug) {
    cout << "gen_random_long(): " << ans << "\n";
  }

  return ans;
}

long long gen_random_long_long(const long long min = -1000000007LL, const long long max = 1000000007LL, const bool _debug = false) {
  default_random_engine engine(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<long long> distribution(min, max);
  long long ans = distribution(engine);

  if (_debug) {
    cout << "gen_random_long_long(): " << ans << "\n";
  }

  return ans;
}

double gen_random_double(const double min = -1000000007.0, const double max = 1000000007.0, const bool _debug = false) {
  default_random_engine engine(chrono::system_clock::now().time_since_epoch().count());
  uniform_real_distribution<double> distribution(min, max);
  double ans = distribution(engine);

  if (_debug) {
    cout << "gen_random_double(): " << ans << "\n";
  }

  return ans;
}

string gen_random_string(const int length = 10, const bool with_space = false, const bool _debug = false) {
  vector<char> char_space = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
  };

  int len = length;
  if (with_space) {
    len = (int) (len / 2);
  }

  default_random_engine engine(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> distribution(0, char_space.size());

  int i;
  string s(length, ' ');
  for (i = 0; i < len; i++) {
    s[i] = char_space[distribution(engine)];
  }
  if (with_space) {
    for (++i; i < length; i++) {
      s[i] = char_space[distribution(engine)];
    }
  }

  if (_debug) {
    cout << "gen_random_string(): " << s << "\n";
  }

  return s;
}


