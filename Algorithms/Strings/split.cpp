#include<bits/stdc++.h>

using namespace std;

vector<string> split(const string& s, const string& d) {
  vector<string> v;

  size_t start = 0;
  size_t end = s.find_first_of(d);
  while (end != string::npos) {
    v.emplace_back(s.substr(start, end - start));
    start = end + 1;
    end = s.find_first_of(d, start);
  }
  v.emplace_back(s.substr(start, s.size() - start));

  return v;
}

void split_to_container(const string& s, const string& d, vector<string>& v) {
  size_t start = 0;
  size_t end = s.find_first_of(d);
  while (end != string::npos) {
    v.emplace_back(s.substr(start, end - start));
    start = end + 1;
    end = s.find_first_of(d, start);
  }
  v.emplace_back(s.substr(start, s.size() - start));
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
      s = "Black Lives Matter";
    } else {
      s = "Black";
    }
    cout << s << "\n";
  }

  return s;
}

void out_vector_string(vector<string>& v) {  
  cout << "Output String Vector: [ ";
  if(v.size() > 0) {
      cout << "\"" << *v.begin() << "\"";
      for(auto itr = ++v.begin(); itr != v.end(); itr++) {
          cout << ", \"" << *itr << "\"";
      }
  }
  cout << " ]\n";
}

int main() {
  string s = inp_string();

  vector<string> v = split(s, "");

  out_vector_string(v);

  return 0;
}