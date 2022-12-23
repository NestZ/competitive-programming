#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for(auto it = d.b;it != d.e;++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

vector<vector<char>> rotate45(vector<vector<char>> arr) {
  int r = arr.size();
  int c = arr[0].size();
  int n = r + c - 1;
  vector<vector<char>> res(n, vector<char>(n, ' '));
  int sr = 0;
  int sc = r - 1;
  for (int i = 0;i < c;i++) {
    int cr = sr;
    int cc = sc;
    for (int j = 0;j < r;j++) {
      res[cr][cc] = arr[j][i];
      cr++;
      cc--;
    }
    sr++;
    sc++;
  }
  return res;
}

vector<vector<char>> rotate90(vector<vector<char>> arr) {
  int r = arr.size();
  int c = arr[0].size();
  vector<vector<char>> res(c, vector<char>(r));
  for (int i = 0;i < c;i++) {
    for (int j = 0;j < r;j++) {
      res[i][j] = arr[r - j - 1][i];
    }
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int r, c;cin >> r >> c;
  vector<vector<char>> arr(r, vector<char>(c));
  for (int i = 0;i < r;i++) {
    for (int j = 0;j < c;j++) {
      cin >> arr[i][j];
    }
  }
  int a;cin >> a;
  while(a > 0) {
    if (a >= 90) {
      arr = rotate90(arr);
      a -= 90;
    } else {
      arr = rotate45(arr);
      a -= 45;
    }
  }
  for (int i = 0;i < arr.size();i++) {
    for (int j = 0;j < arr[0].size();j++) {
      cout << arr[i][j];
    }
    cout << endl;
  }
}
