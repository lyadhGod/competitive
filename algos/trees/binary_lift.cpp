#include <bits/stdc++.h>
#include "../../helpers/helpers.h"

using namespace std;

/**
 *  `BinaryLift` is a class to deal with logarithmic calculations of node-ancestor related problems
 *
 * `Depth` class is coming from /Trees/depth.cpp#Depth
 * `depth` is a Depth type member which deals with depth calculations
 
 * `lifter` is a vector of lists as vectors which deals with binary lift caching
 *
 * `parent` is a tree as vector where each index is a node and it's value is it's parent
 * root node has itself as it's parent
 *
 * `initLifter` intializes the binary lift cache
 * TOTAL TIME: O(NlogN) 
 * TOTAL SPACE: O(NlogN) 
 *
 * `caclLifter` calculates the binary lift cache considering that lifter is initialized
 * TOTAL TIME: O(NlogN) 
 * TOTAL SPACE: O(NlogN) 
 *
 * `initLifter_caclLifter` populates the binary lift cache
 * TOTAL TIME: O(NlogN) 
 * TOTAL SPACE: O(NlogN) 
 *
 * `initLifter` intializes the binary lift cache wihtout precalculating the max depth
 * TOTAL TIME: O(N) if lifter was empty; O(NlogN) is lifter was not empty;
 * TOTAL SPACE: O(N)
 *
 * `caclLifter_withoutPreCalcDepth` calculates the binary lift cache wihtout precalculating the max depth
 * TOTAL TIME: O(NlogN) 
 * TOTAL SPACE: O(NlogN) 
 *
 * `initLifter_caclLifter` populates the binary lift cache wihtout precalculating the max depth
 * TOTAL TIME: O(NlogN) 
 * TOTAL SPACE: O(NlogN) 
 */
class BinaryLift {
  public:
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

    Depth depth;
    vector<vector<int>> lifter;

    vector<vector<int>> initLifter(const vector<int>& parent) {
      int i;
      
      int m = this->lifter.size();
      for (m--; m >= 0 ; m--) {
        this->lifter[m].clear();
      }
      this->lifter.clear();

      this->depth.initDepth_calcDepthAll(parent);

      int n = this->depth.depth.size();

      this->lifter.resize(n);

      int max = *max_element(this->depth.depth.begin(), this->depth.depth.end());
      int d = 1;
      while (max >>= 1) d++;

      for (i = 0; i < n; i++) {
        this->lifter[i].resize(d, -1);

        if (parent[i] != i) {
          this->lifter[i][0] = parent[i];
        }
      }

      return this->lifter;
    }

    vector<vector<int>> caclLifter() {
      int n = this->lifter.size();
      int m = this->lifter[0].size();

      int i, j, k, p;
      for (j = 1; j < m; j++) {
        for (i = 0; i < n; i++) {
          k = this->lifter[i][j - 1];
          if (k != -1) {
            p = this->lifter[k][j - 1];
            if (p != -1) {
              this->lifter[i][j] = p;
            }
          }
        }
      }

      return this->lifter;
    }

    vector<vector<int>> initLifter_caclLifter(const vector<int>& parent) {
      this->initLifter(parent);
      this->caclLifter();

      return this->lifter;
    }

    vector<vector<int>> initLifter_withoutPreCalcDepth(const vector<int>& parent) {
      int i;
      
      int m = this->lifter.size();
      for (m--; m >= 0 ; m--) {
        this->lifter[m].clear();
      }
      this->lifter.clear();

      int n = parent.size();
      
      this->lifter.resize(n);

      for (i = 0; i < n; i++) {
        if (parent[i] != i) {
          this->lifter[i].emplace_back(parent[i]);
        }
      }

      return this->lifter;
    }

    vector<vector<int>> caclLifter_withoutPreCalcDepth() {
      int n = this->lifter.size();

      int i, j, k, p;
      
      j = 1;
      bool q = true;
      while (q) {
        q = false;
        for (i = 0; i < n; i++) {
          if (this->lifter[i].size() == j) {
            k = this->lifter[i][j - 1];
            if (this->lifter[k].size() == j) {
              p = this->lifter[k][j - 1];

              this->lifter[i].emplace_back(p);

              q = true;
            }
          }
        }
        j++;
      }

      return this->lifter;
    }

    vector<vector<int>> initLifter_caclLifter_withoutPreCalcDepth(const vector<int>& parent) {
      this->initLifter_withoutPreCalcDepth(parent);
      this->caclLifter_withoutPreCalcDepth();

      return this->lifter;
    }
};

int main() {
  auto parent = inp_tree("parent");

  auto binaryLift = BinaryLift();

  auto initLifter_caclLifter = binaryLift.initLifter_caclLifter(parent);
  out_unweighted_graph(initLifter_caclLifter, "BinaryLift.initLifter_caclLifter()");

  auto initLifter_caclLifter_withoutPreCalcDepth = binaryLift.initLifter_caclLifter_withoutPreCalcDepth(parent);
  out_unweighted_graph(initLifter_caclLifter_withoutPreCalcDepth, "BinaryLift.initLifter_caclLifter_withoutPreCalcDepth()");

  return 0;
}