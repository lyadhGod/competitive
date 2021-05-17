#include<bits/stdc++.h>

using namespace std;

void out_string(const string& s) {  
  cout << "Output String: \"" << s << "\"\n";
}

void out_string_vector(const vector<string>& v) {  
  cout << "Output String Vector: [ ";
  if(v.size() > 0) {
      auto start = v.begin(), end = v.end();

      cout << "\"" << *start << "\"";
      for(auto itr = ++start; itr != end; itr++) {
          cout << ", \"" << *itr << "\"";
      }
  }
  cout << " ]\n";
}

void out_graph(const unordered_map<int, vector<int>>& g) {  
  cout << "Output Graph: {\n";
  auto starti = g.begin(), endi = g.end();
  for (auto itri = starti; itri != endi; itri++) {
    cout << "[" << itri->first << "] -> ";

    auto startj = itri->second.begin(), endj = itri->second.end();
    if (startj != endj) {
      cout << *startj; 
      for (auto itrj = ++startj; itrj != endj; itrj++) {
        cout << " -> " << *itrj;
      }
      cout << "\n";
    }
  } 
  cout << "}\n";
}
