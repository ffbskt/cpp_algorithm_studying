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
// #include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for(int i = 0; i < n; ++i)

// 06.08.2018 http://codeforces.com/contest/1016/problem/C
namespace CF48 {
  //try to undestand tutorial
  const int N = 300 * 1000 + 9;
  void p3() {
    

    int n = 3;
    int a[2][N];
    long long sum123[2][N];
    long long sum321[2][N];
    long long sum111[2][N];

    cin >> n;
    for(int i = 0; i < 2; ++i)
		for(int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    
    cout << sum123[0][n];

    // for(int i = 0; i < 2; ++i) {
	// 	for(int j = n - 1; j >= 0; --j){
	// 		sum123[i][j] = sum123[i][j + 1] + (j + 1) * 1LL * a[i][j];
	// 		//sum321[i][j] = sum321[i][j + 1] + (n - j) * 1LL * a[i][j];
	// 		//sum111[i][j] = sum111[i][j + 1] + a[i][j];
	// 	}
    // }
		
	// for(int i = 0; i < 2; ++i) {
	// 	for(int j = n - 1; j >= 0; --j){
	// 		cout << i << ' ' << j << " : ";
	// 		cout << sum123[i][j] << "  " << sum321[i][j] << "  " << sum111[i][j] << endl;
	// 	}		
    // }
  }
}

// 13 CF #479 d3 http://codeforces.com/contest/977 last 3 problem
namespace CF479 {
  
  vector<long long int> start_vert(long long int u, 
                         map<long long int, int> am, 
                         vector<long long int> seq, int n) {
    am[u]--;
    if (seq.size() == n - 1) {
      seq.push_back(u);
      return seq;
    }
    if (am.find(u * 2) != am.end() && am[u * 2] > 0) {
      seq.push_back(u);
      //am[u * 2]--;
      return start_vert(u * 2, am, seq, n);
    } 
    if (am.find(u / 3) != am.end() && am[u / 3] > 0) {
      seq.push_back(u);
      // am[u / 3]--;
      return start_vert(u /3, am, seq, n);
    }
    if (seq.size() == n) {
      return seq;
    }
    return vector<long long int>();
  }

  void p3() {
    long long int n, b;
    cin >> n;
    map<long long int, int> a;
    forn(i, n) {
        cin >> b;
        if (a.find(b) == a.end()) {
          a[b] = 1;
        } else {
          a[b] += 1;     
        }
    }
    for (map<long long int, int>::iterator it = a.begin(); it != a.end(); ++it) {
      vector<long long int> seq;
      seq = start_vert(it->first, a, seq, n);
      if (seq.size() == n) {
        forn(i,n) {
            cout << seq[i] << ' ';
        }
        return;
      }
    }
  }  

}


//15 CF #503 d2 http://codeforces.com/contest/1020/countdown
namespace CF503 {
  int hi(int fa, int a, int b) {
    int c = min(abs(fa - a), abs(fa - b));
    
    return c;
  }

  void p1() {
    int a, b, n, h, k, fa, fb, ta, tb;
    cin >> n >> h >> a >> b >> k;
    int arr[k][4];
    forn(i, k) {
      cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }

    forn(i, k) {
      
      fa = arr[i][1];
      fb = arr[i][3];
      int c = abs(fa - fb);
      if (!(a <= fa && fa <= b) && !(a <= fb && fb <= b)) {
         c = hi(fa, a,b) + hi(fb,a,b);
         if ((max(fa, fb) > b && min(fa, fb) < a) || arr[i][0] == arr[i][2]) {
           c = abs(fa - fb);
         }
      }
      cout << abs(arr[i][2] - arr[i][0]) + c << '\n';
    }
  }

  void f2(vector<pair<int, int> > arr, int i) {
      while (arr[i].second) {
        arr[i].second = 0;
        i = arr[i].first;
      }
      cout << i + 1 << ' ';
  }
  void p2() {
    int n;
    cin >> n;
    vector<pair<int, int> > arr(n, make_pair(1,1));
    forn(i, n) {
      cin >> arr[i].first;
      --arr[i].first;
    }
    forn(i, n) {
      f2(arr, i);
    }
  }
  
}

int main(int argc, char const *argv[])
{
    // vector<int> g[3];
    // g[2].push_back(2);
    // cout << g[2][0];

    CF503::p2();
    //cout << ((3^4)^5);
    /* code */
    return 0;
}
