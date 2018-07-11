#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <cmath>
#include <queue>
#include <unordered_map>

using namespace std;
#define forn(i, n) for(int i = 0; i < n; ++i)

// 10072018 EdxC
// 11 CF #490 d3
void p1() {
  int n, k, s = 0;
  cin >> n >> k;
  bool rev = true;
  vector<int> a(n);
  forn(i, n) {
    cin >> a[i];
  }
  forn(i, n) {
    // cout << i;
    if (a[i] > k && rev) {
      reverse(a.begin(), a.end());
      i = 0;
      rev = false;
    } 
    if (a[i] > k && !rev) {
      break;
    }
    ++s;
  }
  cout << s;
}

void p2() {
    int n;
    string str;
    cin >> n >> str;
    vector<int> div;
  for (int i = n; i > 0; --i) {
      if (!(n % i)) {
        div.push_back(i);
      }
  }
  reverse(div.begin(), div.end());
  for (auto e : div) {
    reverse(str.begin(), str.begin() + e);
  }
  cout << str;
}

void p3() {
  int n, k;
  char v;
  cin >> n >> k;
  vector<int> letters(n);
  forn(i, n) {
    cin >> v;
    letters[i] = int(v);
  } 
  forn(i, 26) {
    int rem = i + 97;
    // cout << char(rem);
    for (auto& j : letters) {
      if (j == rem) {
        j = 0;
        if (!--k) {
          for (auto a : letters) {
            if (a) {
              cout << char(a);  
            }  
          }
          return;
        }
      }
    }  
  }
}

// 11 EdxC

namespace EdxC{
  
  struct Node {
    int v;
    int line;
    int ind;
    Node(int val, int line, int ind) : v(val), line(line), ind(ind) {}
    Node(Node&&);
    Node& operator=(Node&& n) {
      v = n.v;
      return *this;
    }
  };

  Node::Node(Node&& n) : v{n.v} {}
  // Node::Node& operator=(Node&& n) {
  //   v = n.v;
  //   return *this;
  // }


  int main() {
    char command;

    Node a(1,2,3), b(3,4,5);
    swap(a, b);
    cout << a.v << a.line << b.v << b.line;

    int n, v;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
      std::cin >> command;
      switch (command) {
        case 'A':
          std::cout << 'a';
        case 'B':
          std::cout << 'b';
      }
    }
  }

}



int main(int argc, char const *argv[])
{
    
    using EdxC::main;
    main(); 
    return 0;
}
