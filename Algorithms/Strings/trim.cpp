#include<bits/stdc++.h>

using namespace std;

// Time: O(N); Space: O(N);
string l_trim(const string& s, const string& d = " ", const bool _debug = false) {
  size_t start = s.find_first_not_of(d);

  if (start == string::npos) {
    return "";
  }

  size_t last = s.size();
  string ans = s.substr(start, last - start);

  if (_debug) {
    cout << "l_trim(): \"" << ans << "\"\n";
  }

  return ans;
}

// Time: O(N); Space: O(N);
string r_trim(const string& s, const string& d = " ", const bool _debug = false) {
  size_t last = s.find_last_not_of(d);

  if (last == string::npos) {
    return "";
  }

  size_t start = 0;
  string ans = s.substr(start, last - start + 1);

  if (_debug) {
    cout << "r_trim(): \"" << ans << "\"\n";
  }

  return ans;
}

// Time: O(N); Space: O(N);
string trim(const string& s, const string& d = " ", const bool _debug = false) {
  size_t start = s.find_first_not_of(d);

  if (start == string::npos) {
    return "";
  }

  size_t last = s.find_last_not_of(d);
  string ans = s.substr(start, last - start + 1);

  if (_debug) {
    cout << "r_trim(): \"" << ans << "\"\n";
  }

  return ans;
}

string inp_string(const bool with_space = true, const bool _dummy = true) {
  string s;

  cout << "Input String: ";
  if (!_dummy) {
    if (with_space) {
      getline(cin, s);
    } else {
      cin >> s;
    }
  } else {
    if (with_space) {
      s = "  Black Lives Matter  ";
    } else {
      s = "  Black  ";
    }
    cout << s << "\n";
  }

  return s;
}

int main() {
  string s = inp_string();

  string str = trim(s, " ", true);

  return 0;
}
