#include <bits/stdc++.h>
#include "../../Helpers/helpers.h"

using namespace std;

// `Depth` is a class to deal with node's depth calculation in a given tree
// `parent` is a tree as vector where each index is a node and it's value is it's parent
// root node has itself as it's parent
class Depth {
  public:
    // `depth` is a vector where each index is a node and it's value is it's distance from the root of tree in `parent`
    vector<int> depth;

    // TOTAL TIME: O(N)
    // TOTAL SPACE: O(N)
    // `init_depth` intializes the depth vector
    vector<int> init_depth(const vector<int>& parent) {
      int n = parent.size();

      this->depth.resize(n);

      int i;
      for (i = 0; i < n; i++) {
        this->depth[i] = (parent[i] == i) ? 0 : -1;
      }

      return this->depth;
    }

    // TOTAL TIME: O(N)
    // TOTAL SPACE: O(1)
    // `calc_depth` calculates the depth of a node considering atleast the root node distance is initalized
    int calc_depth(const vector<int>& parent, const int node) {
      int dist = 0;

      if (this->depth[node] == -1) {
        int index = node;

        while (this->depth[index] == -1) {
          dist++;
          index = parent[index];
        }

        dist += this->depth[index];

        index = node;
        while (this->depth[index] == -1) {
          this->depth[index] = dist;
          dist--;
          index = parent[index];
        }
      }

      return dist;
    }

    // TOTAL TIME: O(N)
    // TOTAL SPACE: O(1)
    // `calc_depth_all` is responsible for calculating the depth vector considering the depth vector is initialized
    vector<int> calc_depth_all(const vector<int>& parent) {
      int n = parent.size();

      int i;
      for (i = 0; i < n; i++) {
        this->calc_depth(parent, i);
      }

      return this->depth;
    }

    // TOTAL TIME: O(N)
    // TOTAL SPACE: O(N)
    // `calc_depth_all` is responsible for populating the depth vector
    vector<int> perform_depth_calc(const vector<int>& parent) {
      this->init_depth(parent);
      this->calc_depth_all(parent);

      return this->depth;
    }
};

int main() {
  auto parent = inp_tree("parent");

  auto depth = Depth();
  auto perform_depth_calc = depth.perform_depth_calc(parent);

  out_vector_int(perform_depth_calc, "Depth.perform_depth_calc()", true);

  return 0;
}
