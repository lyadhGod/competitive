#include<bits/stdc++.h>

using namespace std;

// Time: O(N); Space: O(N); 
vector<string> split(const string& s, const string& d = " ", const bool _debug = false) {
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
    vector<string>::const_iterator start = v.begin(), end = v.end(), itr;
    cout << "split(): [ ";
    for(itr = start; itr != end; itr++) {
      cout << "\"" << *itr << "\", "; 
    }
    cout << "]\n";
  }

  return v;
}

// Time: O(N); Space: O(N); 
void split_to_container(vector<string>& v, const string& s, const string& d = " ", const bool _debug = false) {
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
    vector<string>::const_iterator start = v.begin(), end = v.end(), itr;
    cout << "split_to_container(): [ ";
    for(itr = start; itr != end; itr++) {
      cout << "\"" << *itr << "\", "; 
    }
    cout << "]\n";
  }
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
      s = "Black Lives Matter";
    } else {
      s = "Black";
    }
    cout << s << "\n";
  }

  return s;
}

int main() {
  string s = inp_string();

  vector<string> v = split(s, " ", true);

  return 0;
}
