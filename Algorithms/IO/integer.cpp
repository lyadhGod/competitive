#include<bits/stdc++.h>
#include "../../Helpers/helpers.h"

using namespace std;
 
// `Input` is a class to deal with fast integer inputting
class Input {
  public:
    // TOTAL TIME: O(M) 
    // TOTAL SPACE: O(1) 
    // `fast_inp_int` inputs int value into num
    void fast_inp_int(int& num, const char& delim = ' ') {
      bool negative = false;
      int c;

      c = getchar();
      while (c == delim) {
          c = getchar();
      };
      if (c == '-') {
          negative = true;
          c = getchar();
      }

      num = 0;
      for (; (c > 47 && c < 58); c = getchar()) {
          num = (num << 3) + (num << 1) + (c - 48);
      }

      if (negative) {
          num *= -1;
      }
    }

    // TOTAL TIME: O(M) 
    // TOTAL SPACE: O(1) 
    // `fast_inp_long_long` inputs long long value into num
    void fast_inp_long_long(long long& num, const char& delim = ' ') {
      bool negative = false;
      register int c;

      c = getchar();
      while (c == delim) {
          c = getchar();
      };
      if (c == '-') {
          negative = true;
          c = getchar();
      }

      num = 0LL;
      for (; (c > 47 && c < 58); c = getchar()) {
          num = (num << 3) + (num << 1) + (c - 48);
      }

      if (negative) {
          num *= -1;
      }
    }

    // TOTAL TIME: O(NM) 
    // TOTAL SPACE: O(N) 
    // `fast_inp_vector_int` inputs int vector into vect
    void fast_inp_vector_int(vector<int>& vect, const char& delim = ' ') {
      int n = vect.size();

      int i;
      for (i = 0; i < n; i++) {
        fast_inp_int(vect[i], delim);
      }
    }

    // TOTAL TIME: O(NM) 
    // TOTAL SPACE: O(N) 
    // `fast_inp_vector_long_long` inputs long long vector into vect
    void fast_inp_vector_long_long(vector<long long>& vect, const char& delim = ' ') {
      int n = vect.size();

      int i;
      for (i = 0; i < n; i++) {
        fast_inp_long_long(vect[i], delim);
      }
    }
};

int main() {
  Input input;

  int a;
  cout << "enter int: ";
  input.fast_inp_int(a);
  out_int(a, "Input.fast_inp_int()");

  long long b;
  cout << "enter long long: ";
  input.fast_inp_long_long(b);
  out_long_long(b, "Input.fast_inp_long_long()");

  vector<int> c(a);
  cout << "enter int vector (\' \' separated values): ";
  input.fast_inp_vector_int(c);
  out_vector_int(c, "Input.fast_inp_vector_int()");

  vector<long long> d(a);
  cout << "enter long long vector (\' \' separated values): ";
  input.fast_inp_vector_long_long(d);
  out_vector_long_long(d, "Input.fast_inp_vector_long_long()");
  
  return 0;
}
