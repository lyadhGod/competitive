#include <bits/stdc++.h>
#include "../../helpers/helpers.h"

using namespace std;

/**
 *  `DisjointSets` is a class to deal with querying disjoints sets
 *
 * `sets` is a set of trees as vector where each index is a node and it's value is it's parent
 * root nodes of the trees have a negative value whose absolute value gives the count of nodes in the tree
 * 
 * `initSets` intializes the sets where every node is part of a different set
 * TOTAL TIME: O(N) 
 * TOTAL SPACE: O(N)
 * 
 * `find` finds the root of the set and returns a pair of <node, -set_nodes_count> considering that `sets` is already initialized
 * TOTAL TIME: O(logN) 
 * TOTAL SPACE: O(1)
 * 
 * `union` union-merges 2 sets and returns the root of the new set as a pair of <node, -set_nodes_count> considering that `sets` is already initialized
 * TOTAL TIME: O(logN) 
 * TOTAL SPACE: O(1)
 */
class DisjointSets {
  public:
    vector<int> sets;

    vector<int> initSets(const int& nodes_count) {
      sets.clear();
      sets.resize(nodes_count, -1);

      return sets;
    }

    pair<int, int> find(const int& node) {
      int temp = node;
      while (this->sets[temp] > 0) temp = this->sets[temp];

      int temp1 = node, temp2;
      while (true) {
        temp2 = this->sets[temp1];

        if (temp2 == temp || temp2 < 0) break;

        this->sets[temp1] = temp;
        temp1 = temp2;
      }

      pair<int, int> p(temp, this->sets[temp]);

      return p;
    }

    pair<int, int> _union(const int& node1, const int& node2) {
      pair<int, int> root1 = this->find(node1);
      pair<int, int> root2 = this->find(node2);

      pair<int, int> from = root1, to = root2;
      if (root1.second < root2.second) {
        from = root2;
        to = root1;
      }

      if (from.first != to.first) {
        this->sets[to.first] += this->sets[from.first];
        this->sets[from.first] = to.first;
      }

      pair<int, int> res(to.first, this->sets[to.first]);

      return res;
    }
};

int main() {
  int nodes_count = 10;

  auto disjoint_sets = DisjointSets();

  auto initSets = disjoint_sets.initSets(nodes_count);
  out_vector_int(initSets, "DisjointSets.initSets()", true);

  while (inp_int("quit (0)?", false) != 0) {
    auto choice = inp_int("find (0) / union (1)?", true, 0, 1);
    if (choice == 0) {
      auto node = inp_int("node", true, 0 , nodes_count - 1);

      auto find = disjoint_sets.find(node);
      out_pair_int(find, "DisjointSets.find()");
    } else {
      auto node1 = inp_int("node1", true, 0 , nodes_count - 1);
      auto node2 = inp_int("node2", true, 0 , nodes_count - 1);

      auto _union = disjoint_sets._union(node1, node2);
      out_pair_int(_union, "DisjointSets._union()");
    }
    out_vector_int(disjoint_sets.sets, "DisjointSets.sets", true);
  }

  return 0;
}