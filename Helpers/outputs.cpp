#include<bits/stdc++.h>

using namespace std;

void out_string(string& s) {  
  cout << "Output String: " << s << "\n";
}

void out_string_vector(vector<string>& v) {  
  cout << "Output String Vector: [ ";
  if(v.size() > 0) {
      cout << "\"" << *v.begin() << "\"";
      for(auto itr = ++v.begin(); itr != v.end(); itr++) {
          cout << ", \"" << *itr << "\"";
      }
  }
  cout << " ]\n";
}