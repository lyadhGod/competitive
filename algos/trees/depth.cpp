#include <bits/stdc++.h>
#include "../../helpers/helpers.h"

using namespace std;

/**
 * `Depth` is a class to deal with node's depth calculation in a given tree
 *
 * `depth` is a vector where each index is a node and it's value is it's distance from the root of tree in `parent`
 *
 * `parent` is a tree as vector where each index is a node and it's value is it's parent
 * root node has itself as it's parent
 *
 * `initDepth` intializes the depth vector
 * TOTAL TIME: O(N)
 * TOTAL SPACE: O(N)
 *
 * `calcDepth` calculates the depth of a node considering atleast the root node distance is initalized
 * TOTAL TIME: O(N)
 * TOTAL SPACE: O(1)
 *
 * `calcDepthAll` is responsible for calculating the depth vector considering the depth vector is initialized
 * TOTAL TIME: O(N)
 * TOTAL SPACE: O(1)
 *
 * `calcDepthAll` is responsible for populating the depth vector
 * TOTAL TIME: O(N)
 * TOTAL SPACE: O(N)
 */
class Depth {
  public:
    vector<int> depth;

    vector<int> initDepth(const vector<int>& parent) {
      int n = parent.size();

      this->depth.clear();
      this->depth.resize(n);

      int i;
      for (i = 0; i < n; i++) {
        this->depth[i] = (parent[i] == i) ? 0 : -1;
      }

      return this->depth;
    }

    int calcDepth(const vector<int>& parent, const int node) {
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

    vector<int> calcDepthAll(const vector<int>& parent) {
      int n = parent.size();

      int i;
      for (i = 0; i < n; i++) {
        this->calcDepth(parent, i);
      }

      return this->depth;
    }

    vector<int> initDepth_calcDepthAll(const vector<int>& parent) {
      this->initDepth(parent);
      this->calcDepthAll(parent);

      return this->depth;
    }
};

int main() {
  auto parent = inp_tree("parent");

  auto depth = Depth();
  auto initDepth_calcDepthAll = depth.initDepth_calcDepthAll(parent);

  out_vector_int(initDepth_calcDepthAll, "Depth.initDepth_calcDepthAll()", true);

  return 0;
}
