#include<bits/stdc++.h>

using namespace std;

// Time: O(N); Space: O(N); 
vector<string> split(const string& s, const string& d = " ") {
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

  return v;
}

// Time: O(N); Space: O(N); 
void split_to_container(vector<string>& v, const string& s, const string& d = " ") {
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
}

string inp_string(const bool with_space = true, const bool wants_dummy = true) {
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

void out_vector_string(const vector<string>& v) {  
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

  vector<string> v; split_to_container(v, s, " ");

  out_vector_string(v);

  return 0;
}
