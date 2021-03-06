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
#include <unordered_set>

using namespace std;
#define forn(i, n) for(int i = 0; i < n; ++i)

// 10 EdxC
// 11 CF #490 d3
namespace CF490 {

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

}
// 11 EdxC, 12, 13

namespace EdxC{
  
  struct Node {
    int v;
    int line;
    int ind;
    Node(int val, int line, int ind) : v(val), line(line), ind(ind) {}
    Node() : v(-1) {}
    Node(Node&&);
    Node(const Node&) = default;
    Node& operator=(Node&& n);
  };

  class PQ {
    public:
    vector<Node> qu;
    vector<Node> hs;
    // int cur_line;
    
      PQ(int lines) : hs(lines) {} 
      Node parent(const Node&);
      Node left(Node);
      Node right(Node);
      void sift_d(Node);
      void sift_u(Node);
      void add(int line, int val);
      void pop_min();
      void change_v(int line, int newv);
  };

  Node::Node(Node&& n) : v{n.v} {}
  Node& Node::operator=(Node&& n) {
    v = n.v;
    return *this;
  }

  Node PQ::parent(const Node& node) {
    return qu[node.ind / 2];
  }

  Node PQ::left(Node node) {
    return qu[2 * node.ind - 1];
  }

  Node PQ::right(Node node) {
    return qu[2 * node.ind];
  }

  void PQ::add(int line, int val) {
    hs[line] = Node(val, line, qu.size());
    qu.push_back(hs[line]);
    sift_u(hs[line]);
  }

  void PQ::change_v(int line, int val) {
    hs[line].v = val;
    sift_d(hs[line]);
    sift_u(hs[line]);
  }

  void PQ::sift_d(Node node) {
    int ind = node.ind;
    Node min_n;
    if (left(node).v > right(node).v) {
      min_n = right(node);
    } else {
      min_n = right(node);
    }
    if (node.v > min_n.v ) {
      // Node n = parent(node);
      swap(node, min_n);
    } 
    sift_d(qu[ind]); 
  }

  void PQ::sift_u(Node node) {
    if (node.ind == 0) { return;}
    if (node.v < parent(node).v) {
      Node n = parent(node);
      swap(node, n);
    }
    sift_u(node); 
  }


  int main() {
    char command;

    Node a(1,2,3), b(3,4,5);
    PQ pq(3);
    pq.add(1, 1);
    pq.add(2, -1);
    pq.add(3, -4);
    forn(i, 3) { cout << pq.qu[i].v; }
    Node nq = pq.parent(pq.qu[0]);
    swap(pq.qu[1], nq);
    cout << pq.qu[1].v << a.line << b.v << b.line;

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


  // EdxC 13
  void p7() {

  }

}


// 12 CF #481 d3 http://codeforces.com/contest/978/problem/C
namespace CF481 {
  void p1() {
    int n, v;
    cin >> n;
    vector<int> vec(n), ht(1001), nv;
    forn(i, n) {
      cin >> vec[i];
    }
    reverse(vec.begin(), vec.end());
    forn(i, n) {
      if (!ht[vec[i]]) {
        nv.push_back(vec[i]);
        ht[vec[i]] = 1;
      }
    }
    reverse(nv.begin(), nv.end());
    cout << nv.size() << '\n';
    forn(i,nv.size()) {
      cout << nv[i] << ' ';
    }
  }

  void p2() {
    int n, x_c = 0, rm_c = 0;
    string st;
    cin >> n >> st;
    forn (i, n) {
      if (st[i] == 'x' && x_c == 2) {
        ++rm_c;
      } else if (st[i] == 'x') {
        ++x_c;
      } else {
        x_c = 0;
      }
    }
    cout << rm_c;
  }

  void p3() {
    int64_t n, r, v;
    cin >> n >> r;
    vector<int64_t> vec(1);
    forn(i, n) {
      cin >> v;
      vec.push_back(vec.back() + v);
    }
    forn(i, r) {
      cin >> v;
      vector<int64_t>::iterator indit = lower_bound(vec.begin(), vec.end(), v);
      int ind = indit - vec.begin();
      cout << ind << ' ' << v - *(indit - 1) << '\n';
    }
  }
}

// 13 CF #479 d3 http://codeforces.com/contest/977
namespace CF479 {
  void p1() {
    int n, k;
    cin >> n >> k;
    forn(i, k) {
      if (n % 10) {
        --n;
      } else {
        n /= 10;
      }
    }
    cout << n;
  }

  void p2() {
    int n;
    string s;
    cin >> n >> s;
    map<string, int> hs;
    // cout << s[1] + s[1 + 1];
    forn(i, n - 1) {
      // string st = string(s[i]) + s[i + 1];
      hs[s.substr(i, 2)] += 1;
    }
    auto x = max_element(hs.begin(), hs.end(), 
              [](pair<string, int> a, pair<string, int> b) {
                return a.second < b.second;
              }); 
    cout << x->first;
  }

  void p3() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    forn(i, n) {
      cin >> vec[i];
    }

    sort(vec.begin(), vec.end());
    if (!k) {
      if (vec[0] <= 1) {
        cout << -1;
        return;
      }   
      cout << vec[0] - 1; 
      return;
    }

    if (vec.size() < k) {
      cout << -1;
      return;
    }
    --k;
    
    
    if (k + 1 < n && vec[k] == vec[k + 1]) {
      cout << -1;
    } else {
      cout << vec[k];
    }

  }
}

// 14 CF http://codeforces.com/contest/1009/problem/B

namespace CF47 {
  void p1() {
    int n, m, g = 0;
    cin >> n >> m;
    vector<int> a(n), c(m);
    forn(i,n) {
      cin >> a[i];
    }
    forn(i, m) {
      cin >> c[i];
    }
    int j = 0;
    forn(i, n) {
      if (j < m && a[i] <= c[j]) {
        ++g;
        ++j;
      }
    }
    cout << g;
  }


  void p2() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a;
    forn(i, n) {
      a.push_back(int(s[i]) - 48);
    }
    reverse(a.begin(), a.end());
    stack<int> ones;
    int k = 0;
    
    
    
    forn(i, n - 1) {
      if (a[i] + 1 == a[i + 1]) {
        swap(a[i - k], a[i + 1]);
      } else if (a[i] == a[i + 1]) {
        ++k;
      } else {
        k = 0;
      }
    }

    reverse(a.begin(), a.end());
    forn (i, n) {
      cout << a[i];
    }
    

  }

}

// 16 EdxC 
namespace EdxC16 {
  void p1shit () {
    int n; 
    string v, av;
    cin >> n;
    unordered_set<string> vert;
    forn(i, n) {
      cin >> v >> av;
      
      if (vert.count(av + ", " + v)) {
        cout << "YES";
        return;
      } else {
        vert.insert(v + ", " + av);
      }
    }
    cout << "NO";
  }


  unordered_set<int> bl_vert;
  
  void DFS(const vector<vector<int>>& graph, int v) {
    bl_vert.insert(v);
    for (auto av : graph[v]) {
      if (bl_vert.count(av)) {
        cout << "YES";
        return;
      } else {
        DFS(graph, av);
      }
    }
  }
  
  void p1() {
    int n, m, v, av;
    cin >> n, m;
    vector<vector<int>> graph;
    forn(i, m) {
      cin >> v >> av;
  //?
    DFS(graph, v);
    }
  }


}


int main(int argc, char const *argv[])
{
    
    using namespace CF479;
    p3();
    //EdxC16::p1();
    
    
    return 0;
}
