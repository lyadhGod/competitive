#include <bits/stdc++.h>
#include "../../Helpers/helpers.h"

using namespace std;

// `parent` is a tree as vector where each index is a node and it's value is it's parent
// root node has itself as it's parent
class Depth {
  public:
    // `depth` is a vector where each index is a node and it's value is it's distance from the root of tree in `parent`
    vector<int> depth;

    // TIME: O(N)
    // SPACE: O(N)
    // `init_depth` is responsible for populating the depth vector
    vector<int> init_depth(const vector<int>& parent) {
      int n = parent.size();

      this->depth.resize(n);

      int i;
      for (i = 0; i < n; i++) {
        this->depth[i] = (parent[i] == i) ? 0 : -1;
      }

      int node, dist;
      for (i = 0; i < n; i++) {
        if (this->depth[i] == -1) {
          dist = 0;
          node = i;
          while (this->depth[node] == -1) {
            dist++;
            node = parent[node];
          }

          dist += this->depth[node];

          node = i;
          while (this->depth[node] == -1) {
            this->depth[node] = dist;
            dist--;
            node = parent[node];
          }
        }
      }

      return this->depth;
    }
};

int main() {
  auto parent = inp_tree("parent");

  auto depth = Depth();
  auto init_depth = depth.init_depth(parent);

  out_vector_int(init_depth, "init_depth", true);

  return 0;
}
