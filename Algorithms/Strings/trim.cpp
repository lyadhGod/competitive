#include<bits/stdc++.h>

using namespace std;

string l_trim(const string& s, const string& d = " ") {
  size_t start = s.find_first_not_of(d);

  if (start == string::npos) {
    return "";
  }

  size_t last = s.size();
  return s.substr(start, last - start);
}

string r_trim(const string& s, const string& d = " ") {
  size_t last = s.find_last_not_of(d);

  if (last == string::npos) {
    return "";
  }

  size_t start = 0;
  return s.substr(start, last - start + 1);
}

string trim(const string& s, const string& d = " ") {
  size_t start = s.find_first_not_of(d);

  if (start == string::npos) {
    return "";
  }

  size_t last = s.find_last_not_of(d);
  return s.substr(start, last - start + 1);
}

string inp_string(bool with_space = true, bool wants_dummy = true) {
  string s;

  cout << "Input String: ";
  if (!wants_dummy) {
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

void out_string(string& s) {  
  cout << "Output String: \"" << s << "\"\n";
}

int main() {
  string s = inp_string();

  string str = trim(s);

  out_string(str);

  return 0;
}
